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
#include <string.h>
#include <ctype.h>

#include "neo.h"

/*
 *
 */
int
mat_load_from_csv(matrix_t *mp, char *line, double mval, double cval)
{
	int nvalues;
	char *cp, *xcp;
	double *dp;

	if (mp->columns != 1)
		return(0);
	if ((cp = strpbrk(line, "\r\n")) != NULL)
		*cp = '\0';
	for (nvalues = 0, cp = line, dp = mp->values; cp != NULL && *cp != '\0';) {
		if ((xcp = strchr(cp, ',')) != NULL)
			*xcp++ = '\0';
		if (*cp != '\0') {
			*dp++ = atof(cp) * mval + cval;
			nvalues++;
			cp = xcp;
		}
	}
	return(nvalues);
}
