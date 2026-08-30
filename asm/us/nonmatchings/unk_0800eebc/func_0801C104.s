.syntax unified
	.align 2, 0
	.global func_0801C104
	.thumb
	.thumb_func
	.type func_0801C104, %function
func_0801C104: @ 0801C104
	push {r4, lr}
	ldr r4, _0801C138 @ =0x02039B84
	ldr r3, [r4, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x09
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	beq _0801C18E
	ldr r0, _0801C13C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0801C140
	movs r1, #0x88
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	b _0801C17E
	.byte 0x00, 0x00
_0801C138: .4byte 0x02039B84
_0801C13C: .4byte 0x02039BB0
_0801C140:
	movs r1, #0x88
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801C17E
	ldr r0, _0801C194 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	movs r1, #0x88
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
_0801C17E:
	ldr r0, _0801C198 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _0801C19C @ =0xFFFEFFFF
	ands r1, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
_0801C18E:
	pop {r4}
	pop {r0}
	bx r0
_0801C194: .4byte 0x02039B9C
_0801C198: .4byte 0x02039B84
_0801C19C: .4byte 0xFFFEFFFF
	.byte 0x00, 0x06, 0x01, 0x0E, 0x04, 0x29, 0x07, 0xD8, 0x04, 0x48, 0x02, 0x68, 0xFB, 0x32, 0x01, 0x20
	.byte 0x88, 0x40, 0x11, 0x78, 0x08, 0x43, 0x10, 0x70, 0x70, 0x47, 0x00, 0x00, 0x84, 0x9B, 0x03, 0x02
.syntax divided
