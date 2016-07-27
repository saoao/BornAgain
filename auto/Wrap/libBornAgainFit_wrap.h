/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_libBornAgainFit_WRAP_H_
#define SWIG_libBornAgainFit_WRAP_H_

#include <map>
#include <string>


class SwigDirector_INamed : public INamed, public Swig::Director {

public:
    SwigDirector_INamed(PyObject *self);
    SwigDirector_INamed(PyObject *self, std::string const &name);
    virtual ~SwigDirector_INamed();

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;
};


class SwigDirector_IParameterized : public IParameterized, public Swig::Director {

public:
    SwigDirector_IParameterized(PyObject *self, std::string const &name = "");
    SwigDirector_IParameterized(PyObject *self, IParameterized const &other);
    virtual ~SwigDirector_IParameterized();
    virtual std::string addParametersToExternalPool(std::string path, ParameterPool *external_pool, int copy_number = -1) const;
    virtual void onChange();
    virtual void onChangeSwigPublic() {
      IParameterized::onChange();
    }
    virtual void print(std::ostream &ostr) const;
    virtual void printSwigPublic(std::ostream &ostr) const {
      IParameterized::print(ostr);
    }

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class IParameterized doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[2];
#endif

};


#endif
