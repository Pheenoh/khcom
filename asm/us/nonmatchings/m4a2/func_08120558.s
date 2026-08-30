.syntax unified
	.align 2, 0
	.global func_08120558
	.thumb
	.thumb_func
	.type func_08120558, %function
func_08120558: @ 08120558
	push {lr}
	ldr r0, _081205BC @ =0x03007FF0
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x00]
	ldr r1, _081205C0 @ =0x978C92AD
	adds r0, r0, r1
	cmp r0, #0x01
	bhi _081205B6
	ldrb r0, [r2, #0x04]
	subs r0, #0x01
	ldrb r1, [r2, #0x04]
	strb r0, [r2, #0x04]
	ldrb r0, [r2, #0x04]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bgt _081205B6
	ldrb r0, [r2, #0x0B]
	ldrb r1, [r2, #0x04]
	strb r0, [r2, #0x04]
	ldr r1, _081205C4 @ =0x040000C4
	ldr r0, [r1, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x12
	ands r0, r2
	cmp r0, #0x00
	beq _08120590
	ldr r0, _081205C8 @ =0x84400004
	str r0, [r1, #0x00]
_08120590:
	ldr r1, _081205CC @ =0x040000D0
	ldr r0, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _0812059E
	ldr r0, _081205C8 @ =0x84400004
	str r0, [r1, #0x00]
_0812059E:
	ldr r2, _081205D0 @ =0x040000C6
	movs r3, #0x80
	lsls r3, r3, #0x03
	adds r0, r3, #0x0
	strh r0, [r2, #0x00]
	ldr r1, _081205D4 @ =0x040000D2
	strh r0, [r1, #0x00]
	movs r3, #0xB6
	lsls r3, r3, #0x08
	adds r0, r3, #0x0
	strh r0, [r2, #0x00]
	strh r0, [r1, #0x00]
_081205B6:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081205BC: .4byte 0x03007FF0
_081205C0: .4byte 0x978C92AD
_081205C4: .4byte 0x040000C4
_081205C8: .4byte 0x84400004
_081205CC: .4byte 0x040000D0
_081205D0: .4byte 0x040000C6
_081205D4: .4byte 0x040000D2
.syntax divided
