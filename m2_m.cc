//
// Generated file, do not edit! Created by nedtool 4.6 from m2.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "m2_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(MessageNoeud);

MessageNoeud::MessageNoeud(const char *name, int kind) : ::cMessage(name,kind)
{
    this->R_var = 0;
    this->T_var = 0;
    this->ID_var = 0;
}

MessageNoeud::MessageNoeud(const MessageNoeud& other) : ::cMessage(other)
{
    copy(other);
}

MessageNoeud::~MessageNoeud()
{
}

MessageNoeud& MessageNoeud::operator=(const MessageNoeud& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MessageNoeud::copy(const MessageNoeud& other)
{
    this->R_var = other.R_var;
    this->T_var = other.T_var;
    this->ID_var = other.ID_var;
}

void MessageNoeud::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->R_var);
    doPacking(b,this->T_var);
    doPacking(b,this->ID_var);
}

void MessageNoeud::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->R_var);
    doUnpacking(b,this->T_var);
    doUnpacking(b,this->ID_var);
}

int MessageNoeud::getR() const
{
    return R_var;
}

void MessageNoeud::setR(int R)
{
    this->R_var = R;
}

int MessageNoeud::getT() const
{
    return T_var;
}

void MessageNoeud::setT(int T)
{
    this->T_var = T;
}

int MessageNoeud::getID() const
{
    return ID_var;
}

void MessageNoeud::setID(int ID)
{
    this->ID_var = ID;
}

class MessageNoeudDescriptor : public cClassDescriptor
{
  public:
    MessageNoeudDescriptor();
    virtual ~MessageNoeudDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MessageNoeudDescriptor);

MessageNoeudDescriptor::MessageNoeudDescriptor() : cClassDescriptor("MessageNoeud", "cMessage")
{
}

MessageNoeudDescriptor::~MessageNoeudDescriptor()
{
}

bool MessageNoeudDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MessageNoeud *>(obj)!=NULL;
}

const char *MessageNoeudDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MessageNoeudDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int MessageNoeudDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *MessageNoeudDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "R",
        "T",
        "ID",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int MessageNoeudDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='R' && strcmp(fieldName, "R")==0) return base+0;
    if (fieldName[0]=='T' && strcmp(fieldName, "T")==0) return base+1;
    if (fieldName[0]=='I' && strcmp(fieldName, "ID")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MessageNoeudDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *MessageNoeudDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MessageNoeudDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MessageNoeud *pp = (MessageNoeud *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MessageNoeudDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MessageNoeud *pp = (MessageNoeud *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getR());
        case 1: return long2string(pp->getT());
        case 2: return long2string(pp->getID());
        default: return "";
    }
}

bool MessageNoeudDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MessageNoeud *pp = (MessageNoeud *)object; (void)pp;
    switch (field) {
        case 0: pp->setR(string2long(value)); return true;
        case 1: pp->setT(string2long(value)); return true;
        case 2: pp->setID(string2long(value)); return true;
        default: return false;
    }
}

const char *MessageNoeudDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *MessageNoeudDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MessageNoeud *pp = (MessageNoeud *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


