.syntax unified
	.align 2, 0
	.global func_080C9EAC
	.thumb
	.thumb_func
	.type func_080C9EAC, %function
func_080C9EAC: @ 080C9EAC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x004
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r7, #0x00
	ldr r5, _080C9EF8 @ =0x096FCB84
	mov r9, r5
	movs r6, #0x00
_080C9EC4:
	mov r0, r9
	adds r0, #0x08
	adds r0, r6, r0
	ldr r1, [r0, #0x00]
	ldr r2, [r5, #0x00]
	ldr r3, [r5, #0x04]
	str r4, [sp, #0x000]
	mov r0, r8
	bl func_080D1990
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, #0x0C
	adds r6, #0x0C
	adds r7, #0x01
	cmp r7, #0x4F
	bls _080C9EC4
	adds r0, r4, #0x0
	add sp, #0x004
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080C9EF8: .4byte 0x096FCB84
.syntax divided
