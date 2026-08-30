.syntax unified
	.align 2, 0
	.global func_0811FDEC
	.thumb
	.thumb_func
	.type func_0811FDEC, %function
func_0811FDEC: @ 0811FDEC
	push {r4, r5, r6, lr}
	ldr r0, _0811FE40 @ =0x0811F1D5
	movs r1, #0x02
	negs r1, r1
	ands r0, r1
	ldr r1, _0811FE44 @ =0x03000000
	ldr r2, _0811FE48 @ =0x04000100
	bl func_08117FE8
	ldr r0, _0811FE4C @ =0x0203C850
	bl func_08120214
	ldr r0, _0811FE50 @ =0x0203D890
	bl func_081200D0
	ldr r0, _0811FE54 @ =0x0095E800
	bl func_08120378
	ldr r0, _0811FE58 @ =0x0000001A
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _0811FE3A
	ldr r5, _0811FE5C @ =0x09D6F60C
	adds r6, r0, #0x0
_0811FE1E:
	ldr r4, [r5, #0x00]
	ldr r1, [r5, #0x04]
	ldrb r2, [r5, #0x08]
	adds r0, r4, #0x0
	bl func_081205D8
	ldrh r0, [r5, #0x0A]
	strb r0, [r4, #0x0B]
	ldr r0, _0811FE60 @ =0x0203DE90
	str r0, [r4, #0x18]
	adds r5, #0x0C
	subs r6, #0x01
	cmp r6, #0x00
	bne _0811FE1E
_0811FE3A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0811FE40: .4byte 0x0811F1D5
_0811FE44: .4byte 0x03000000
_0811FE48: .4byte 0x04000100
_0811FE4C: .4byte 0x0203C850
_0811FE50: .4byte 0x0203D890
_0811FE54: .4byte 0x0095E800
_0811FE58: .4byte 0x0000001A
_0811FE5C: .4byte 0x09D6F60C
_0811FE60: .4byte 0x0203DE90
.syntax divided
