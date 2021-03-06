#include "Core/Histo/Histogram2D.h"
#include "Core/Histo/Histogram1D.h"
#include "Tests/GTestWrapper/google_test.h"
#include <memory>

class Histogram2DTest : public ::testing::Test
{
protected:
    Histogram2DTest();

    Histogram2D hist;
};

// y
// 4.0   -----------------------------------
//       |     |          |     |          |
//       |  2  |    5     |  8  |    11    |
// 2.0   -----------------------------------
//       |  1  |    4     |  7  |    10    |
// 1.0   -----------------------------------
//       |  0  |    3     |  6  |    9     |
// 0.0   -----------------------------------
//     -1.0  -0.5        0.5   1.0        2.0  X

Histogram2DTest::Histogram2DTest() : hist{4, {-1.0, -0.5, 0.5, 1.0, 2.0}, 3, {0.0, 1.0, 2.0, 4.0}}
{
}

TEST_F(Histogram2DTest, VariableHist)
{
    hist.reset();

    // basic axes check
    EXPECT_EQ(size_t(12), hist.getTotalNumberOfBins());
    EXPECT_EQ(hist.getRank(), size_t(2));
    EXPECT_EQ(hist.getXaxis().size(), size_t(4));
    EXPECT_EQ(hist.getXmin(), -1.0);
    EXPECT_EQ(hist.getXmax(), 2.0);
    EXPECT_EQ(hist.getYaxis().size(), size_t(3));
    EXPECT_EQ(hist.getYmin(), 0.0);
    EXPECT_EQ(hist.getYmax(), 4.0);

    // globalbin -> axes indices
    EXPECT_EQ(hist.getXaxisIndex(0), 0u);
    EXPECT_EQ(hist.getXaxisIndex(1), 0u);
    EXPECT_EQ(hist.getXaxisIndex(2), 0u);
    EXPECT_EQ(hist.getXaxisIndex(3), 1u);
    EXPECT_EQ(hist.getXaxisIndex(4), 1u);
    EXPECT_EQ(hist.getXaxisIndex(5), 1u);
    EXPECT_EQ(hist.getXaxisIndex(9), 3u);
    EXPECT_EQ(hist.getXaxisIndex(10), 3u);
    EXPECT_EQ(hist.getXaxisIndex(11), 3u);

    EXPECT_EQ(hist.getYaxisIndex(0), 0u);
    EXPECT_EQ(hist.getYaxisIndex(1), 1u);
    EXPECT_EQ(hist.getYaxisIndex(2), 2u);
    EXPECT_EQ(hist.getYaxisIndex(3), 0u);
    EXPECT_EQ(hist.getYaxisIndex(4), 1u);
    EXPECT_EQ(hist.getYaxisIndex(5), 2u);
    EXPECT_EQ(hist.getYaxisIndex(9), 0u);
    EXPECT_EQ(hist.getYaxisIndex(10), 1u);
    EXPECT_EQ(hist.getYaxisIndex(11), 2u);

    // axes indices -> global bin
    EXPECT_EQ(hist.getGlobalBin(0, 0), size_t(0));
    EXPECT_EQ(hist.getGlobalBin(0, 2), size_t(2));
    EXPECT_EQ(hist.getGlobalBin(1, 1), size_t(4));
    EXPECT_EQ(hist.getGlobalBin(3, 2), size_t(11));

    // bin centers
    EXPECT_EQ(hist.getXaxisValue(0), -0.75);
    EXPECT_EQ(hist.getXaxisValue(2), -0.75);
    EXPECT_EQ(hist.getXaxisValue(4), 0.0);
    EXPECT_EQ(hist.getXaxisValue(10), 1.5);
    EXPECT_EQ(hist.getXaxisValue(11), 1.5);

    EXPECT_EQ(hist.getYaxisValue(0), 0.5);
    EXPECT_EQ(hist.getYaxisValue(2), 3.0);
    EXPECT_EQ(hist.getYaxisValue(4), 1.5);
    EXPECT_EQ(hist.getYaxisValue(10), 1.5);
    EXPECT_EQ(hist.getYaxisValue(11), 3.0);

    // coordinates to global bin
    EXPECT_EQ(hist.findGlobalBin(-0.75, 0.5), size_t(0));
    EXPECT_EQ(hist.findGlobalBin(0.0, 1.5), size_t(4));
    EXPECT_EQ(hist.findGlobalBin(1.5, 3.0), size_t(11));
}

// y
// 4.0   -----------------------------------
//       |     |          |     |          |
//       |  2  |    5     |  8  |    11    |
// 2.0   -----------------------------------
//       |  1  |    4     |  7  |    10    |
// 1.0   -----------------------------------
//       |  0  |    3     |  6  |    9     |
// 0.0   -----------------------------------
//     -1.0  -0.5        0.5   1.0        2.0  X

TEST_F(Histogram2DTest, VariableHistFill)
{
    hist.reset();

    // values to fill all histogram
    std::vector<double> xvalues = {-0.75, -0.75, -0.75, 0.0, 0.0, 0.0,
                                   0.75,  0.75,  0.75,  1.5, 1.5, 1.5};
    std::vector<double> yvalues = {0.5, 1.5, 3.0, 0.5, 1.5, 3.0, 0.5, 1.5, 3.0, 0.5, 1.5, 3.0};

    // put in every histogram bin one double value proportional to globalbin (globalbin*10.0)
    for (size_t i = 0; i < xvalues.size(); ++i) {
        hist.fill(xvalues[i], yvalues[i], i * 10.0);
    }

    // check bin content using globalbin
    for (size_t globalbin = 0; globalbin < hist.getTotalNumberOfBins(); ++globalbin) {
        EXPECT_EQ(globalbin * 10.0, hist.getBinContent(globalbin));
        EXPECT_EQ(1.0, hist.getBinNumberOfEntries(globalbin));
    }

    // check bin content using axes bins
    for (size_t binx = 0; binx < hist.getXaxis().size(); ++binx) {
        for (size_t biny = 0; biny < hist.getYaxis().size(); ++biny) {
            size_t globalbin = hist.getGlobalBin(binx, biny);
            EXPECT_EQ(globalbin * 10.0, hist.getBinContent(binx, biny));
            EXPECT_EQ(1.0, hist.getBinNumberOfEntries(binx, biny));
        }
    }
}

// y
// 4.0   -----------------------------------
//       |     |          |     |          |
//       |  2  |    5     |  8  |    11    |
// 2.0   -----------------------------------
//       |  1  |    4     |  7  |    10    |
// 1.0   -----------------------------------
//       |  0  |    3     |  6  |    9     |
// 0.0   -----------------------------------
//     -1.0  -0.5        0.5   1.0        2.0  X

TEST_F(Histogram2DTest, projectionX)
{
    hist.reset();

    // values to fill all histogram
    std::vector<double> xvalues = {-0.75, -0.75, -0.75, 0.0, 0.0, 0.0,
                                   0.75,  0.75,  0.75,  1.5, 1.5, 1.5};
    std::vector<double> yvalues = {0.5, 1.5, 3.0, 0.5, 1.5, 3.0, 0.5, 1.5, 3.0, 0.5, 1.5, 3.0};
    std::vector<double> content = {1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 1.0, 2.0, 3.0};

    // put in every histogram bin the value from 'content' vector
    for (size_t i = 0; i < xvalues.size(); ++i) {
        hist.fill(xvalues[i], yvalues[i], content[i]);
    }

    // a) create projection along X axis
    std::unique_ptr<Histogram1D> h1(hist.projectionX());
    EXPECT_EQ(hist.getXmin(), h1->getXmin());
    EXPECT_EQ(hist.getXmax(), h1->getXmax());
    EXPECT_EQ(hist.getNbinsX(), h1->getNbinsX());
    EXPECT_EQ(hist.getXaxisValue(0), h1->getXaxisValue(0));
    EXPECT_EQ(hist.getXaxisValue(3), h1->getXaxisValue(1));
    EXPECT_EQ(hist.getXaxisValue(6), h1->getXaxisValue(2));
    EXPECT_EQ(hist.getXaxisValue(9), h1->getXaxisValue(3));

    // check content of projections
    for (size_t binx = 0; binx < h1->getNbinsX(); ++binx) {
        EXPECT_EQ(3, h1->getBinNumberOfEntries(binx));
        EXPECT_EQ(6.0, h1->getBinContent(binx));
        EXPECT_DOUBLE_EQ(std::sqrt(2.0 / 3.0), h1->getBinError(binx));
    }

    // b) create projection along X axis at given y (slice)
    h1.reset(hist.projectionX(1.01));
    EXPECT_EQ(hist.getXmin(), h1->getXmin());
    EXPECT_EQ(hist.getXmax(), h1->getXmax());
    EXPECT_EQ(hist.getNbinsX(), h1->getNbinsX());
    EXPECT_EQ(hist.getXaxisValue(0), h1->getXaxisValue(0));
    EXPECT_EQ(hist.getXaxisValue(3), h1->getXaxisValue(1));
    EXPECT_EQ(hist.getXaxisValue(6), h1->getXaxisValue(2));
    EXPECT_EQ(hist.getXaxisValue(9), h1->getXaxisValue(3));

    // check content of projections
    for (size_t binx = 0; binx < h1->getNbinsX(); ++binx) {
        EXPECT_EQ(1, h1->getBinNumberOfEntries(binx));
        EXPECT_EQ(2.0, h1->getBinContent(binx));
        EXPECT_DOUBLE_EQ(0.0, h1->getBinError(binx));
    }

    // c) create projection along X for y between [ylow, yup]
    h1.reset(hist.projectionX(0.99, 1.01));
    EXPECT_EQ(hist.getXmin(), h1->getXmin());
    EXPECT_EQ(hist.getXmax(), h1->getXmax());
    EXPECT_EQ(hist.getNbinsX(), h1->getNbinsX());
    EXPECT_EQ(hist.getXaxisValue(0), h1->getXaxisValue(0));
    EXPECT_EQ(hist.getXaxisValue(3), h1->getXaxisValue(1));
    EXPECT_EQ(hist.getXaxisValue(6), h1->getXaxisValue(2));
    EXPECT_EQ(hist.getXaxisValue(9), h1->getXaxisValue(3));

    // check content of projections
    for (size_t binx = 0; binx < h1->getNbinsX(); ++binx) {
        EXPECT_EQ(2, h1->getBinNumberOfEntries(binx));
        EXPECT_EQ(3.0, h1->getBinContent(binx));
        EXPECT_DOUBLE_EQ(std::sqrt(0.25), h1->getBinError(binx));
    }
}

// y
// 4.0   -----------------------------------
//       |     |          |     |          |
//       |  2  |    5     |  8  |    11    |
// 2.0   -----------------------------------
//       |  1  |    4     |  7  |    10    |
// 1.0   -----------------------------------
//       |  0  |    3     |  6  |    9     |
// 0.0   -----------------------------------
//     -1.0  -0.5        0.5   1.0        2.0  X

TEST_F(Histogram2DTest, projectionY)
{
    hist.reset();

    // values to fill all histogram
    std::vector<double> xvalues = {-0.75, -0.75, -0.75, 0.0, 0.0, 0.0,
                                   0.75,  0.75,  0.75,  1.5, 1.5, 1.5};
    std::vector<double> yvalues = {0.5, 1.5, 3.0, 0.5, 1.5, 3.0, 0.5, 1.5, 3.0, 0.5, 1.5, 3.0};
    std::vector<double> content = {1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 1.0, 2.0, 3.0};

    // put in every histogram bin the value from 'content' vector
    for (size_t i = 0; i < xvalues.size(); ++i) {
        hist.fill(xvalues[i], yvalues[i], content[i]);
    }

    // a) create projection along Y axis
    std::unique_ptr<Histogram1D> h1(hist.projectionY());
    EXPECT_EQ(hist.getYmin(), h1->getXmin());
    EXPECT_EQ(hist.getYmax(), h1->getXmax());
    EXPECT_EQ(size_t(3), h1->getNbinsX());
    EXPECT_EQ(hist.getNbinsY(), h1->getNbinsX());
    EXPECT_EQ(hist.getYaxisValue(3), h1->getXaxisValue(0));
    EXPECT_EQ(hist.getYaxisValue(4), h1->getXaxisValue(1));
    EXPECT_EQ(hist.getYaxisValue(5), h1->getXaxisValue(2));

    // check content of projections

    for (size_t binx = 0; binx < h1->getNbinsX(); ++binx) {
        EXPECT_EQ(4, h1->getBinNumberOfEntries(binx));
        EXPECT_DOUBLE_EQ(0.0, h1->getBinError(binx));
    }
    EXPECT_EQ(4.0, h1->getBinContent(0));
    EXPECT_EQ(8.0, h1->getBinContent(1));
    EXPECT_EQ(12.0, h1->getBinContent(2));

    // b) create projection along Y axis at given x(slice)
    h1.reset(hist.projectionY(0.0));
    EXPECT_EQ(hist.getYmin(), h1->getXmin());
    EXPECT_EQ(hist.getYmax(), h1->getXmax());
    EXPECT_EQ(size_t(3), h1->getNbinsX());
    EXPECT_EQ(hist.getNbinsY(), h1->getNbinsX());
    EXPECT_EQ(hist.getYaxisValue(3), h1->getXaxisValue(0));
    EXPECT_EQ(hist.getYaxisValue(4), h1->getXaxisValue(1));
    EXPECT_EQ(hist.getYaxisValue(5), h1->getXaxisValue(2));

    // check content of projections

    for (size_t binx = 0; binx < h1->getNbinsX(); ++binx) {
        EXPECT_EQ(1, h1->getBinNumberOfEntries(binx));
        EXPECT_DOUBLE_EQ(0.0, h1->getBinError(binx));
    }
    EXPECT_EQ(1.0, h1->getBinContent(0));
    EXPECT_EQ(2.0, h1->getBinContent(1));
    EXPECT_EQ(3.0, h1->getBinContent(2));

    // c) create projection along Y axis for x's between [xlow,xup]
    h1.reset(hist.projectionY(0.0, 0.51));
    EXPECT_EQ(hist.getYmin(), h1->getXmin());
    EXPECT_EQ(hist.getYmax(), h1->getXmax());
    EXPECT_EQ(size_t(3), h1->getNbinsX());
    EXPECT_EQ(hist.getNbinsY(), h1->getNbinsX());
    EXPECT_EQ(hist.getYaxisValue(3), h1->getXaxisValue(0));
    EXPECT_EQ(hist.getYaxisValue(4), h1->getXaxisValue(1));
    EXPECT_EQ(hist.getYaxisValue(5), h1->getXaxisValue(2));

    // check content of projections

    for (size_t binx = 0; binx < h1->getNbinsX(); ++binx) {
        EXPECT_EQ(2, h1->getBinNumberOfEntries(binx));
        EXPECT_DOUBLE_EQ(0.0, h1->getBinError(binx));
    }
    EXPECT_EQ(2.0, h1->getBinContent(0));
    EXPECT_EQ(4.0, h1->getBinContent(1));
    EXPECT_EQ(6.0, h1->getBinContent(2));
}

// y
// 4.0   -----------------------------------
//       |     |          |     |          |
//       |  2  |    5     |  8  |    11    |
// 2.0   -----------------------------------
//       |  1  |    4     |  7  |    10    |
// 1.0   -----------------------------------
//       |  0  |    3     |  6  |    9     |
// 0.0   -----------------------------------
//     -1.0  -0.5        0.5   1.0        2.0  X

TEST_F(Histogram2DTest, crop)
{
    hist.reset();

    // values to fill all histogram
    std::vector<double> xvalues = {-0.75, -0.75, -0.75, 0.0, 0.0, 0.0,
                                   0.75,  0.75,  0.75,  1.5, 1.5, 1.5};
    std::vector<double> yvalues = {0.5, 1.5, 3.0, 0.5, 1.5, 3.0, 0.5, 1.5, 3.0, 0.5, 1.5, 3.0};
    std::vector<double> content = {1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 1.0, 2.0, 3.0};

    // put in every histogram bin the value from 'content' vector
    for (size_t i = 0; i < xvalues.size(); ++i) {
        hist.fill(xvalues[i], yvalues[i], content[i]);
    }

    std::unique_ptr<Histogram2D> crop(hist.crop(-0.49, 0.0, 1.99, 1.9));
    EXPECT_EQ(-0.5, crop->getXmin());
    EXPECT_EQ(2.0, crop->getXmax());
    EXPECT_EQ(size_t(3), crop->getNbinsX());
    EXPECT_EQ(0.0, crop->getYmin());
    EXPECT_EQ(2.0, crop->getYmax());
    EXPECT_EQ(size_t(2), crop->getNbinsY());

    EXPECT_EQ(1.0, crop->getBinContent(0, 0));
    EXPECT_EQ(2.0, crop->getBinContent(0, 1));
    EXPECT_EQ(1.0, crop->getBinContent(1, 0));
    EXPECT_EQ(2.0, crop->getBinContent(1, 1));
    EXPECT_EQ(1.0, crop->getBinContent(2, 0));
    EXPECT_EQ(2.0, crop->getBinContent(2, 1));
}

TEST_F(Histogram2DTest, CreateHistogram)
{
    OutputData<double> data;
    data.addAxis("x-axis", 10, 0.0, 10.0);
    data.addAxis("y-axis", 5, -5.0, 0.0);
    for (size_t i = 0; i < data.getAllocatedSize(); ++i) {
        data[i] = double(i);
    }

    std::unique_ptr<IHistogram> h2(IHistogram::createHistogram(data));
    EXPECT_EQ(size_t(2), h2->getRank());
    EXPECT_EQ(data.getAllocatedSize(), h2->getTotalNumberOfBins());
    EXPECT_EQ(data.getAxis(0).getMin(), h2->getXmin());
    EXPECT_EQ(data.getAxis(0).getMax(), h2->getXmax());
    EXPECT_EQ(data.getAxis(1).getMin(), h2->getYmin());
    EXPECT_EQ(data.getAxis(1).getMax(), h2->getYmax());
    for (size_t i = 0; i < h2->getTotalNumberOfBins(); ++i) {
        EXPECT_EQ(data[i], h2->getBinContent(i));
        EXPECT_EQ(data[i], h2->getBinAverage(i));
        EXPECT_EQ(1, h2->getBinNumberOfEntries(i));
        EXPECT_EQ(0.0, h2->getBinError(i));
    }
}

TEST_F(Histogram2DTest, CreateOutputData)
{
    Histogram2D h2(10, -5.0, 5.0, 5, -5.0, 0.0);

    for (size_t nx = 0; nx < h2.getNbinsX(); ++nx) {
        for (size_t ny = 0; ny < h2.getNbinsY(); ++ny) {
            double value(1.0 * ny + nx * h2.getNbinsY());
            size_t globalbin = h2.getGlobalBin(nx, ny);
            h2.fill(h2.getXaxisValue(globalbin), h2.getYaxisValue(globalbin), value);
        }
    }

    std::unique_ptr<OutputData<double>> data(h2.createOutputData(IHistogram::DataType::INTEGRAL));
    EXPECT_EQ(size_t(2), data->getRank());
    EXPECT_EQ(data->getAllocatedSize(), h2.getTotalNumberOfBins());
    EXPECT_EQ(data->getAxis(0).getMin(), h2.getXmin());
    EXPECT_EQ(data->getAxis(0).getMax(), h2.getXmax());
    EXPECT_EQ(data->getAxis(1).getMin(), h2.getYmin());
    EXPECT_EQ(data->getAxis(1).getMax(), h2.getYmax());
    for (size_t i = 0; i < data->getAllocatedSize(); ++i) {
        EXPECT_EQ(double(i), (*data)[i]);
    }

    data.reset(h2.createOutputData(IHistogram::DataType::AVERAGE));
    for (size_t i = 0; i < data->getAllocatedSize(); ++i) {
        EXPECT_EQ(double(i), (*data)[i]);
    }

    data.reset(h2.createOutputData(IHistogram::DataType::STANDARD_ERROR));
    for (size_t i = 0; i < data->getAllocatedSize(); ++i) {
        EXPECT_EQ(0.0, (*data)[i]);
    }

    data.reset(h2.createOutputData(IHistogram::DataType::NENTRIES));
    for (size_t i = 0; i < data->getAllocatedSize(); ++i) {
        EXPECT_EQ(1.0, (*data)[i]);
    }
}

TEST_F(Histogram2DTest, GetMaximumGetMinimum)
{
    Histogram2D h2(10, -5.0, 5.0, 5, -5.0, 0.0);

    for (size_t ix = 0; ix < h2.getNbinsX(); ++ix) {
        for (size_t iy = 0; iy < h2.getNbinsY(); ++iy) {
            h2.fill(-5.0 + ix + 0.5, -5.0 + iy + 0.5, 10.0 + ix + h2.getNbinsX() * iy);
        }
    }

    EXPECT_EQ(10.0, h2.getMinimum());
    EXPECT_EQ(size_t(0), h2.getMinimumBinIndex());
    EXPECT_EQ(59.0, h2.getMaximum());
    EXPECT_EQ(size_t(49), h2.getMaximumBinIndex());
}
