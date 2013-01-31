#ifndef OUTPUTDATATEST_H
#define OUTPUTDATATEST_H

#include "OutputData.h"
#include <algorithm>

#include "gtest/gtest.h"

class OutputDataTest : public ::testing::Test
{
protected:
    OutputDataTest();
    virtual ~OutputDataTest();

    OutputData<int> int_data_0d;
    OutputData<float> fl_data_1d;
    OutputData<double> db_data_3d;
    std::vector<size_t> zero_3d_coordinate;
};

OutputDataTest::OutputDataTest()
{
    zero_3d_coordinate.push_back(0);
    zero_3d_coordinate.push_back(0);
    zero_3d_coordinate.push_back(0);
    AxisDouble angle_axis("angle", 20, 0.0, 0.1);
    AxisDouble length_axis("length", 10, 0.0, 0.5);
    AxisDouble index_axis("index", 10, 1, 10);
    fl_data_1d.addAxis(angle_axis);

    db_data_3d.addAxis(angle_axis);
    db_data_3d.addAxis(length_axis);
    db_data_3d.addAxis(index_axis);
    OutputData<double>::iterator it = db_data_3d.begin();
    for (size_t i=0; i<2000; ++i)
    {
        *it = (double)i;
        ++it;
    }
}

OutputDataTest::~OutputDataTest()
{
}

TEST_F(OutputDataTest, SingleElementAfterConstruction)
{
    EXPECT_EQ((size_t)1, int_data_0d.getAllocatedSize());
}

TEST_F(OutputDataTest, SizeAfterAddingAxes)
{
    EXPECT_EQ((size_t)1, int_data_0d.getAllocatedSize());
    EXPECT_EQ((size_t)20, fl_data_1d.getAllocatedSize());
    EXPECT_EQ((size_t)2000, db_data_3d.getAllocatedSize());
}

TEST_F(OutputDataTest, DataInitialization)
{
    std::vector<int> coordinates;
    coordinates.push_back(11);
    coordinates.push_back(4);
    coordinates.push_back(3);
    EXPECT_DOUBLE_EQ((double)1143, db_data_3d[db_data_3d.toIndex(coordinates)]);
}

TEST_F(OutputDataTest, DataCopying)
{
    OutputData<double> data1;
    OutputData<double> data2;
    data1.addAxis("axis1", 10, 0., 10.);
    data2.addAxis("axis1", 10, 0., 10.);
    EXPECT_TRUE( data1.hasSameDimensions(data2));
    EXPECT_TRUE( data1.hasSameShape(data2));

    data1.addAxis("axis2", 10, 0., 10.);
    data2.addAxis("axis2", 10, 1., 10.);
    EXPECT_TRUE( data1.hasSameDimensions(data2));
    EXPECT_FALSE( data1.hasSameShape(data2));

    data2.copyFrom(data1);
    EXPECT_TRUE( data1.hasSameDimensions(data2));
    EXPECT_TRUE( data1.hasSameShape(data2));

    data1.addAxis("axis3", 10, 0., 10.);
    data2.addAxis("axis3another", 10, 0., 10.);
    EXPECT_TRUE( data1.hasSameDimensions(data2));
    EXPECT_FALSE( data1.hasSameShape(data2));

    data1.setAllTo(10);
    data2.copyFrom(data1);
    EXPECT_TRUE( data1.totalSum() == data2.totalSum() );
    EXPECT_TRUE( data1.hasSameDimensions(data2));
    EXPECT_TRUE( data1.hasSameShape(data2));
    EXPECT_TRUE( data2.hasSameDimensions(data1));
    EXPECT_TRUE( data2.hasSameShape(data1));
    EXPECT_TRUE( data1.hasSameDimensions(data1));
    EXPECT_TRUE( data1.hasSameShape(data1));
    EXPECT_TRUE( data2.hasSameDimensions(data2));
    EXPECT_TRUE( data2.hasSameShape(data2));

}

TEST_F(OutputDataTest, MaxElement)
{
    OutputData<double > data;
    data.addAxis("axis1", 10, 0., 10.);
    data.addAxis("axis2", 2, 0., 10.);
    data.setAllTo(1.0);

    OutputData<double >::iterator it = data.begin();
    for (size_t i=0; i<data.getAllocatedSize(); ++i) if(i==10) (*it)=10.0;
    OutputData<double >::const_iterator cit = std::max_element(data.begin(), data.end());
    EXPECT_EQ( double(10.0), (*cit));
}

TEST_F(OutputDataTest, ValueOfAxis)
{
    OutputData<double > data;
    data.addAxis("axis1", 10, 0., 9.);
    data.addAxis("axis2", 2, 0., 10.);
    EXPECT_EQ( double(0.0), data.getValueOfAxis("axis1", 0));
    EXPECT_EQ( double(0.0), data.getValueOfAxis("axis2", 0));
    EXPECT_EQ( double(0.0), data.getValueOfAxis("axis1", 1));
    EXPECT_EQ( double(10.0), data.getValueOfAxis("axis2", 1));
    EXPECT_EQ( double(1.0), data.getValueOfAxis("axis1", 2));
    EXPECT_EQ( double(0.0), data.getValueOfAxis("axis2", 2));
    EXPECT_EQ( double(9.0), data.getValueOfAxis("axis1", 19));
    EXPECT_EQ( double(10.0), data.getValueOfAxis("axis2", 19));
}


#endif // OUTPUTDATATEST_H