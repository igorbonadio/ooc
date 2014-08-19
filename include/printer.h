#ifndef PRINTER_H
#define PRINTER_H

/********************** Printer ********************/
/*
 * interface Printer
 *   void print();
 * }
 *
 */

struct PrinterInterface {
  const char* name;
  void (* print) (void* self);
};

#endif
