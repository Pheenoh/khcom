.syntax unified
	.align 2, 0
	.global func_08009418
	.thumb
	.thumb_func
	.type func_08009418, %function
func_08009418: @ 08009418
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r5, #0x83
	lsls r5, r5, #0x03
	adds r0, r5, #0x0
	bl func_08000918
	adds r6, r0, #0x0
	movs r7, #0x00
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0x05
	adds r0, r0, r4
	lsls r0, r0, #0x02
	subs r0, r0, r4
	lsls r0, r0, #0x04
	mov r8, r0
_08009442:
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl func_080089E0
	lsls r4, r7, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #0x05
	adds r1, r1, r4
	lsls r1, r1, #0x02
	subs r1, r1, r4
	lsls r1, r1, #0x03
	ldr r0, _08009484 @ =0x0E001EC0
	adds r1, r1, r0
	add r1, r8
	adds r0, r6, #0x0
	adds r2, r5, #0x0
	bl WriteAndVerifySramFast
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x01
	ble _08009442
	adds r0, r6, #0x0
	bl func_080009C4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08009484: .4byte 0x0E001EC0
.syntax divided
