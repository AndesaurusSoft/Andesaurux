#ifndef __STDARG_H__
#define __STDARG_H__

typedef char* va_list;

#define va_start(list, param) (list = (va_list)&param + sizeof(param))
#define va_arg(list, type) (*(type *)((list += sizeof(type)) - sizeof(type)))
#define va_end(list) (list = nullptr) __builtin_va_end(list)

#endif // __STDARG_H__