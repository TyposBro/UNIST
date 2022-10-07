	.file	"bof.c"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	secret
	.section	.rodata
	.align	3
.LC0:
	.string	"cBWTwTwC5eKAcDxpwx88"
	.section	.sdata,"aw"
	.align	3
	.type	secret, @object
	.size	secret, 8
secret:
	.dword	.LC0
	.section	.rodata
	.align	3
.LC1:
	.string	"Ah! %s\n"
	.text
	.align	1
	.globl	print_secret
	.type	print_secret, @function
print_secret:
	addi	sp,sp,-16
	sd	ra,8(sp)
	sd	s0,0(sp)
	addi	s0,sp,16
	lui	a5,%hi(secret)
	ld	a5,%lo(secret)(a5)
	mv	a1,a5
	lui	a5,%hi(.LC1)
	addi	a0,a5,%lo(.LC1)
	call	printf
	nop
	ld	ra,8(sp)
	ld	s0,0(sp)
	addi	sp,sp,16
	jr	ra
	.size	print_secret, .-print_secret
	.globl	buffer
	.bss
	.align	3
	.type	buffer, @object
	.size	buffer, 256
buffer:
	.zero	256
	.globl	i
	.section	.sbss,"aw",@nobits
	.align	2
	.type	i, @object
	.size	i, 4
i:
	.zero	4
	.text
	.align	1
	.globl	receive_input
	.type	receive_input, @function
receive_input:
	addi	sp,sp,-144
	sd	ra,136(sp)
	sd	s0,128(sp)
	addi	s0,sp,144
	jal	hello
	li	a0,2
	jal	add
	mv	a0,a0
	jal	dump
	lui	a5,%hi(_impure_ptr)
	ld	a5,%lo(_impure_ptr)(a5)
	ld	a5,8(a5)
	mv	a2,a5
	li	a1,256
	lui	a5,%hi(buffer)
	addi	a0,a5,%lo(buffer)
	call	fgets
	addi	a4,s0,-144
	lui	a5,%hi(buffer)
	addi	a1,a5,%lo(buffer)
	mv	a0,a4
	call	strcpy
	nop
	ld	ra,136(sp)
	ld	s0,128(sp)
	addi	sp,sp,144
	jr	ra
	.size	receive_input, .-receive_input
	.section	.rodata
	.align	3
.LC2:
	.string	"Can you obtain the secret?"
	.text
	.align	1
	.globl	run
	.type	run, @function
run:
	addi	sp,sp,-16
	sd	ra,8(sp)
	sd	s0,0(sp)
	addi	s0,sp,16
	lui	a5,%hi(.LC2)
	addi	a0,a5,%lo(.LC2)
	call	puts
	call	receive_input
	nop
	mv	a0,a5
	ld	ra,8(sp)
	ld	s0,0(sp)
	addi	sp,sp,16
	jr	ra
	.size	run, .-run
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-16
	sd	ra,8(sp)
	sd	s0,0(sp)
	addi	s0,sp,16
	call	run
	li	a5,0
	mv	a0,a5
	ld	ra,8(sp)
	ld	s0,0(sp)
	addi	sp,sp,16
	jr	ra
	.size	main, .-main
	.ident	"GCC: (g5964b5cd727) 11.1.0"
