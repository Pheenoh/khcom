.syntax unified
	.align 2, 0
	.global func_080D69AC
	.thumb
	.thumb_func
	.type func_080D69AC, %function
func_080D69AC: @ 080D69AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r6, r5, #0x0
	bl func_08001390
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080D69E4
	movs r0, #0x65
	bl func_0811FE70
	movs r1, #0x00
	ldsh r0, [r4, r1]
	bl func_080D6908
	lsls r0, r0, #0x10
	ldr r1, _080D69E0 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	cmp r0, #0x00
	bge _080D6A10
	adds r2, r5, #0x0
	b _080D6A10
_080D69E0: .4byte 0xFFFF0000
_080D69E4:
	bl func_08001390
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080D6A1C
	movs r0, #0x65
	bl func_0811FE70
	movs r1, #0x00
	ldsh r0, [r4, r1]
	bl func_080D6908
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	lsls r1, r6, #0x10
	cmp r0, r1
	ble _080D6A10
	movs r2, #0x00
_080D6A10:
	ldr r0, _080D6A24 @ =0x096FDCC8
	lsls r1, r2, #0x10
	asrs r1, r1, #0x0E
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	strh r0, [r4, #0x00]
_080D6A1C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D6A24: .4byte 0x096FDCC8
.syntax divided
