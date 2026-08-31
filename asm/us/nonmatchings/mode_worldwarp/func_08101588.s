.syntax unified
	.align 2, 0
	.global func_08101588
	.thumb
	.thumb_func
	.type func_08101588, %function
func_08101588: @ 08101588
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov r10, r1
	ldr r0, [sp, #0x020]
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	movs r7, #0x00
	cmp r7, r9
	bge _081015DA
	subs r0, #0x01
	muls r0, r5
	adds r6, r0, r2
_081015AE:
	mov r0, r8
	movs r1, #0x0A
	bl __umodsi3
	adds r4, r0, #0x0
	mov r0, r8
	movs r1, #0x0A
	bl __udivsi3
	mov r8, r0
	adds r0, r4, #0x0
	muls r0, r5
	add r0, r10
	adds r4, r7, #0x1
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	bl RequestDma3Copy
	subs r6, r6, r5
	adds r7, r4, #0x0
	cmp r7, r9
	blt _081015AE
_081015DA:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
