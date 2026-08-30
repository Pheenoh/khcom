.syntax unified
	.align 2, 0
	.global func_080BB588
	.thumb
	.thumb_func
	.type func_080BB588, %function
func_080BB588: @ 080BB588
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	adds r4, r6, #0x0
	adds r4, #0x08
	adds r5, r6, #0x0
	adds r7, r6, #0x0
	adds r7, #0x9C
_080BB5A0:
	ldrh r1, [r4, #0x0C]
	adds r0, r4, #0x0
	mov r2, r8
	bl func_0800589C
	adds r4, #0x34
	adds r5, #0x34
	cmp r5, r7
	ble _080BB5A0
	adds r4, r6, #0x0
	adds r4, #0x9C
	adds r0, r6, #0x0
	bl func_080BB518
	adds r2, r6, #0x0
_080BB5BE:
	ldr r0, [r2, #0x0C]
	ldr r1, [r2, #0x00]
	subs r0, r0, r1
	asrs r0, r0, #0x01
	adds r1, r1, r0
	str r1, [r2, #0x00]
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x04]
	subs r0, r0, r1
	asrs r0, r0, #0x01
	adds r1, r1, r0
	str r1, [r2, #0x04]
	adds r2, #0x34
	cmp r2, r4
	ble _080BB5BE
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
