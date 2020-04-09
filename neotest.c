/*
 * Copyright (c) 2020, Tynan Pinball Limited.  All rights reserved.  This is
 * free software; you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software
 * Foundation; either version 2, or (at your option) any later version.
 *
 * It is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this product; see the file COPYING.  If not, write to the Free
 * Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * THIS SOFTWARE IS PROVIDED BY TYNAN PINBALL LIMITED "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL TYNAN PINBALL LIMITED BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ABSTRACT
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "neo.h"

double x1[] = {4, 5, 6, 2, 3, 7};
double x2[] = {2, 4, 6, 1, 2, 3};
double x3[] = {1, 0, 1, 0, 1, 2};
double x4[] = {3, 5, -1, 0, 2, -1};
double x5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

/*
 *
 */
int
main(int argc, char *argv[])
{
	matrix_t *mp1, *mp2, *mp3;

	srand(time(NULL));
	mp1 = mat_identity(4);
	mat_dump(mp1, "Identity Matrix");
	mat_free(mp1);
	mp1 = mat_alloc(2, 3);
	mat_set_array(mp1, x1);
	mat_dump(mp1, "Matrix 'A'");
	mp2 = mat_alloc(2, 3);
	mat_set_array(mp2, x2);
	mat_dump(mp2, "Matrix 'B'");
	mat_subtract(mp1, mp2);
	mat_dump(mp1, "Result (A - B)");
	mp1 = mat_alloc(2, 3);
	mat_set_array(mp1, x3);
	mat_dump(mp1, "Matrix 'A'");
	mp2 = mat_alloc(3, 2);
	mat_set_array(mp2, x4);
	mat_dump(mp2, "Matrix 'B'");
	mp3 = mat_multiply(mp1, mp2);
	mat_dump(mp3, "Result (A x B)");
	mp1 = mat_alloc(2, 3);
	mat_set_array(mp1, x1);
	mat_dump(mp1, "Source A");
	mp2 = mat_transpose(mp1);
	mat_dump(mp2, "Result A.T");
	mp1 = mat_alloc(3, 3);
	mat_set_array(mp1, x5);
	mat_dump(mp1, "Source A");
	mp2 = mat_transpose(mp1);
	mat_dump(mp2, "Result A.T");
	mp1 = mat_alloc(8, 8);
	mat_normalize(mp1, 0, 0.01);
	mat_dump(mp1, "Normal 0/0.01");
	mp1 = mat_alloc(8, 8);
	mat_normalize(mp1, 5, 0.1);
	mat_dump(mp1, "Normal 5/0.1");
	mp1 = mat_alloc(9, 1);
	mat_set_array(mp1, x5);
	mp2 = mat_transpose(mp1);
	mat_dump(mp2, "Transpose 1-dimensonal array");
}
