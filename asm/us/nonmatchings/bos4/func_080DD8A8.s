.syntax unified
	.align 2, 0
	.global func_080DD8A8
	.thumb
	.thumb_func
	.type func_080DD8A8, %function
func_080DD8A8: @ 080DD8A8
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	movs r7, #0xF0
	movs r5, #0x00
	mov r4, sp
_080DD8B4:
	strb r7, [r4, #0x00]
	bl func_080DC510
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD8C8
	movs r0, #0x00
	ldsb r0, [r4, r0]
	negs r0, r0
	strb r0, [r4, #0x00]
_080DD8C8:
	adds r0, r6, #0x4
	ldr r1, _080DD8F8 @ =0x09EF5268
	mov r2, sp
	bl func_08000E14
	lsls r2, r5, #0x02
	adds r1, r6, #0x0
	adds r1, #0x18
	adds r1, r1, r2
	str r0, [r1, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r5, #0x01
	cmp r5, #0x09
	ble _080DD8B4
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080DD8F8: .4byte 0x09EF5268
.syntax divided
