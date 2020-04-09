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

#include "neo.h"

/*
 *
 */
void
mat_dump(matrix_t *mp, char *comment)
{
	int r, c;
	double *dp = mp->values;

	if (comment != NULL)
		printf(">> %s (%d X %d):\n", comment, mp->rows, mp->columns);
	else
		printf(">> Matrix %d X %d:\n", mp->rows, mp->columns);
	for (r = 0; r < mp->rows; r++) {
		putchar('|');
		for (c = 0; c < mp->columns; c++)
			printf(" %10.3e |", *dp++);
		putchar('\n');
	}
}
