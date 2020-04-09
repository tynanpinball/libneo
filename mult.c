/*
 * Copyright (c) 2020, Tynan Pinball Limited.  All rights reserved.
 * Unpublished rights reserved under the copyright laws of the United
 * States and/or the Republic of Ireland.
 *
 * The software contained herein is proprietary to and embodies the
 * confidential technology of Tynan Pinball Limited.  Possession, use,
 * duplication or dissemination of the software and media is authorized
 * only pursuant to a valid written license from Tynan Pinball Limited.
 *
 * RESTRICTED RIGHTS LEGEND   Use, duplication, or disclosure by the U.S.
 * Government is subject to restrictions as set forth in Subparagraph
 * (c)(1)(ii) of DFARS 252.227-7013, or in FAR 52.227-19, as applicable.
 *
 * THIS SOFTWARE IS PROVIDED BY TYNAN PINBALL LIMITED "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL TYNAN PINBALL LIMITED
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
