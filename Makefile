#
# Copyright (c) 2020, Tynan Pinball Limited.  All rights reserved.  This is
# free software; you can redistribute it and/or modify it under the terms
# of the GNU General Public License as published by the Free Software
# Foundation; either version 2, or (at your option) any later version.
#
# It is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public License along
# with this product; see the file COPYING.  If not, write to the Free
# Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
#
# THIS SOFTWARE IS PROVIDED BY TYNAN PINBALL LIMITED "AS IS" AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL TYNAN PINBALL LIMITED BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
# THE POSSIBILITY OF SUCH DAMAGE.
#
AR=	/usr/bin/ar
RANLIB=	/usr/bin/ranlib
CFLAGS=	-Wall -O

SRCS=	alloc.c \
		identity.c \
		set.c \
		mean.c \
		stddev.c \
		normal.c \
		add.c \
		mult.c \
		transpose.c \
		csv.c \
		iter.c \
		dump.c
OBJS=	$(SRCS:.c=.o)
LIB=	libneo.a

all:	$(LIB) neotest

install: $(LIB)

clean:
	rm -f $(LIB) $(OBJS) neotest neotest.o

neotest: $(LIB) neotest.o
	$(CC) -o neotest neotest.o -L. -lneo -lm

$(LIB):	$(OBJS)
	$(AR) rc $@ $?
	$(RANLIB) $@

$(OBJS): neo.h
