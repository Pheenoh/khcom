.syntax unified
	.align 2, 0
	.global func_080CA4E8
	.thumb
	.thumb_func
	.type func_080CA4E8, %function
func_080CA4E8: @ 080CA4E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, [sp, #0x018]
	ldr r5, [sp, #0x01C]
	ldr r6, [sp, #0x020]
	ldr r7, [sp, #0x024]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r12, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r1, #0x00
	str r1, [r7, #0x00]
	str r1, [r6, #0x00]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	adds r0, r2, r5
	cmp r0, #0x00
	blt _080CA52A
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	subs r0, r2, r0
	cmp r0, #0xF0
	ble _080CA530
	subs r0, #0xF0
_080CA52A:
	lsls r0, r0, #0x08
	str r0, [r6, #0x00]
	movs r1, #0x01
_080CA530:
	mov r2, r12
	lsls r0, r2, #0x10
	asrs r4, r0, #0x10
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r0, r4, r0
	cmp r0, #0x00
	blt _080CA54E
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, r4, r0
	cmp r0, #0xA0
	ble _080CA554
	subs r0, #0xA0
_080CA54E:
	lsls r0, r0, #0x08
	str r0, [r7, #0x00]
	movs r1, #0x01
_080CA554:
	adds r0, r1, #0x0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
