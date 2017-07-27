#pragma once

struct __TrueType {
};

struct __FalseType {
};

template <class type>
struct TypeTraits {
   typedef __FalseType    has_trivial_default_constructor;
   typedef __FalseType    has_trivial_copy_constructor;
   typedef __FalseType    has_trivial_assignment_operator;
   typedef __FalseType    has_trivial_destructor;
   typedef __FalseType    is_POD_type;
};

template <>
struct TypeTraits<char> {
	typedef __TrueType    has_trivial_default_constructor;
	typedef __TrueType    has_trivial_copy_constructor;
	typedef __TrueType    has_trivial_assignment_operator;
	typedef __TrueType    has_trivial_destructor;
	typedef __TrueType    is_POD_type;
};

template <>
struct TypeTraits<int> {
	typedef __TrueType    has_trivial_default_constructor;
	typedef __TrueType    has_trivial_copy_constructor;
	typedef __TrueType    has_trivial_assignment_operator;
	typedef __TrueType    has_trivial_destructor;
	typedef __TrueType    is_POD_type;
};

template<class type>
struct TypeTraits<type*> {
	typedef __TrueType    has_trivial_default_constructor;
	typedef __TrueType    has_trivial_copy_constructor;
	typedef __TrueType    has_trivial_assignment_operator;
	typedef __TrueType    has_trivial_destructor;
	typedef __TrueType    is_POD_type;
};