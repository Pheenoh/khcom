.syntax unified
	.align 2, 0
	.global func_080CFF58
	.thumb
	.thumb_func
	.type func_080CFF58, %function
func_080CFF58: @ 080CFF58
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	mov r8, r1
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r2, _080CFFB4 @ =0x02034E20
	ldr r0, [r2, #0x00]
	ldr r1, [r5, #0x00]
	ldr r0, [r0, #0x1C]
	subs r3, r1, r0
	ldr r0, _080CFFB8 @ =0xFFFFFA00
	adds r7, r2, #0x0
	cmp r3, r0
	blt _080CFF80
	movs r0, #0xA0
	lsls r0, r0, #0x04
	cmp r3, r0
	ble _080CFF82
_080CFF80:
	adds r3, r0, #0x0
_080CFF82:
	lsrs r4, r3, #0x1F
	adds r4, r3, r4
	asrs r4, r4, #0x01
	ldr r0, _080CFFBC @ =0xFFFFFD00
	adds r4, r4, r0
	ldr r0, [r7, #0x00]
	ldr r1, [r0, #0x1C]
	adds r1, r3, r1
	adds r0, r5, #0x0
	adds r2, r6, #0x0
	bl func_080058FC
	ldr r0, [r7, #0x00]
	ldr r0, [r0, #0x20]
	adds r4, r4, r0
	mov r0, r8
	adds r1, r4, #0x0
	adds r2, r6, #0x0
	bl func_080058FC
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CFFB4: .4byte 0x02034E20
_080CFFB8: .4byte 0xFFFFFA00
_080CFFBC: .4byte 0xFFFFFD00
.syntax divided
