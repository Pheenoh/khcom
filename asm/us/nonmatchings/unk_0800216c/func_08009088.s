.syntax unified
	.align 2, 0
	.global func_08009088
	.thumb
	.thumb_func
	.type func_08009088, %function
func_08009088: @ 08009088
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r5, _080090E8 @ =0x00000F14
	adds r0, r5, #0x0
	bl func_08000918
	adds r6, r0, #0x0
	movs r7, #0x00
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r0, _080090EC @ =0x00001E28
	adds r1, r4, #0x0
	muls r1, r0
	mov r8, r1
_080090AC:
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl func_080089E0
	lsls r4, r7, #0x10
	asrs r4, r4, #0x10
	adds r1, r4, #0x0
	muls r1, r5
	ldr r0, _080090F0 @ =0x0E002F20
	adds r1, r1, r0
	add r1, r8
	adds r0, r6, #0x0
	adds r2, r5, #0x0
	bl func_0811817C
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x01
	ble _080090AC
	adds r0, r6, #0x0
	bl func_080009C4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080090E8: .4byte 0x00000F14
_080090EC: .4byte 0x00001E28
_080090F0: .4byte 0x0E002F20
.syntax divided
