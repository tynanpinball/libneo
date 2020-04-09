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
