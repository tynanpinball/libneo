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
#include <math.h>

#include "neo.h"

/*
 *
 */
matrix_t *
mat_multiply(matrix_t *mpa, matrix_t *mpb)
{
	int r, c, n;
	matrix_t *mp;
	double *rdp, *adp;

	if (mpa->columns != mpb->rows)
		return(NULL);
	if ((mp = mat_alloc(mpa->rows, mpb->columns)) == NULL)
		return(NULL);
	for (r = 0, rdp = mp->values; r < mp->rows; r++) {
		for (c = 0; c < mp->columns; c++) {
			*rdp = 0.0;
			adp = &MAT_CELL(mpa, r, 0);
			for (n = 0; n < mpb->rows; n++)
				*rdp += *adp++ * MAT_CELL(mpb, n, c);
			rdp++;
		}
	}
	return(mp);
}

/*
 *
 */
int
mat_scalar_multiply(matrix_t *mp, double value)
{
	int n = mp->rows * mp->columns;
	double *dp = mp->values;

	while (n-- > 0)
		*dp++ *= value;
	return(0);
}
