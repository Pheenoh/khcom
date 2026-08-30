.syntax unified
	.align 2, 0
	.global func_08034704
	.thumb
	.thumb_func
	.type func_08034704, %function
func_08034704: @ 08034704
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldrb r5, [r4, #0x14]
	bl func_08034368
	ldrb r0, [r4, #0x14]
	cmp r5, r0
	beq _08034734
	ldrb r1, [r4, #0x14]
	adds r0, r5, #0x0
	bl func_08005824
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bge _08034726
	negs r0, r0
_08034726:
	cmp r0, #0x64
	ble _0803472E
	movs r0, #0x00
	b _08034732
_0803472E:
	ldr r0, [r4, #0x10]
	asrs r0, r0, #0x01
_08034732:
	str r0, [r4, #0x10]
_08034734:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
