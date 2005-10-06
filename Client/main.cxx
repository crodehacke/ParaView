// -*- c++ -*-

/*
 * Copyright 2004 Sandia Corporation.
 * Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
 * license for use of this work by or on behalf of the
 * U.S. Government. Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that this Notice and any
 * statement of authorship are reproduced on all copies.
 */

#include "pqMainWindow.h"
#include <QApplication>

//----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  QApplication qapplication(argc, argv);
  pqMainWindow qwindow(qapplication);
  qwindow.resize(400, 400);
  qwindow.show();
  return qapplication.exec();
}

