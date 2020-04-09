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
typedef struct	{
	int	rows;
	int	columns;
	double	*values;
} matrix_t;

#define MAT_CELL(mp, r, c)	((mp)->values[(r) * (mp)->columns + (c)])

/*
 * Prototypes...
 */
matrix_t	*mat_alloc(int, int);
matrix_t	*mat_calloc(int, int, double);
int			mat_set_value(matrix_t *, double);
int			mat_load_from_csv(matrix_t *, char *, double, double);
double		mat_mean(matrix_t *);
double		mat_stddev(matrix_t *);
void		mat_normalize(matrix_t *, double, double);
int			mat_set_array(matrix_t *, double *);
matrix_t	*mat_identity(int);
int			mat_add(matrix_t *, matrix_t *);
int			mat_scalar_add(matrix_t *, double);
int			mat_subtract(matrix_t *, matrix_t *);
int			mat_scalar_subtract(matrix_t *, double);
int			mat_scalar_multiply(matrix_t *, double);
matrix_t	*mat_multiply(matrix_t *, matrix_t *);
matrix_t	*mat_transpose(matrix_t *);
void		mat_dump(matrix_t *, char *);
void		mat_free(matrix_t *);
