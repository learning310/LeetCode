	.file	"b.cpp"
	.globl	global
	.bss
	.align 4
global:
	.space 4
	.text
	.globl	_Z1fv
	.def	_Z1fv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z1fv
_Z1fv:
.LFB0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	nop
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 5.1.0"
