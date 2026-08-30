.syntax unified
	.align 2, 0
	.global func_080D44A0
	.thumb
	.thumb_func
	.type func_080D44A0, %function
func_080D44A0: @ 080D44A0
	push {r4, r5, lr}
	add sp, #-0x020
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, _080D44D0 @ =0x096FDC50
	mov r0, sp
	movs r2, #0x20
	bl memcpy
	lsls r5, r5, #0x01
	subs r4, #0x01
	lsls r4, r4, #0x03
	adds r5, r5, r4
	mov r1, sp
	adds r0, r1, r5
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x08
	add sp, #0x020
	pop {r4, r5}
	pop {r1}
	bx r1
_080D44D0: .4byte 0x096FDC50
.syntax divided
