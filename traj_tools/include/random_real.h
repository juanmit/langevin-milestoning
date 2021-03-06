/**
 * Langevin dynamics in 1D with PMF and viscosity.
 * 
 * Copyright 2016 Christopher T. lee <ctlee@ucsd.edu>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */ 

#ifndef RANDOM_REAL_H
#define RANDOM_REAL_H

#ifdef __GNUC
#define __GNUC_PREREQ__(x, y)           \
((__GNUC__ == (x) && __GNUC_MINOR__ >= (y)) ||      \
 (__GNUC__ > (x)))

#define DONT_USE_STRONG_WEAK_ALIAS  1

#else
#define __GNUC_PREREQ__(x, y) 0
#endif

#if __GNUC_PREREQ__(2, 96)
#define __predict_true(exp) __builtin_expect((exp) != 0, 1)
#define __predict_false(exp)  __builtin_expect((exp) != 0, 0)
#else
#define __predict_true(exp) (exp)
#define __predict_false(exp)  (exp)
#endif

#include <pcg_variants.h>

#ifdef __cplusplus
extern "C" {
#endif

double random_real_64(pcg64_random_t* rng);
double random_real_53(pcg64_random_t* rng);
double random_real(pcg64_random_t* rng);

#ifdef __cplusplus
}
#endif
#endif
