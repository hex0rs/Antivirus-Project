/*
 * Quarantine.h
 *
 *  Created on: Apr 9, 2014
 *      Author: abd-el-rahman
 */

#ifndef QUARANTINE_H_
#define QUARANTINE_H_

#include <string>
#include "../Shared.h"
using namespace std;
using namespace Shared::Common;

class Shared::Common::Quarantine {
public:
static int add(string path);
static int remove(string path);
static int restore(string path);
};

#endif /* QUARANTINE_H_ */
