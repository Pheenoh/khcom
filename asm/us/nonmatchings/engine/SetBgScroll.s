.syntax unified
	.align 2, 0
	.global SetBgScroll
	.thumb
	.thumb_func
	.type SetBgScroll, %function
SetBgScroll: @ 080054EC
	adds r3, r0, #0x0
	ldr r0, _08005508 @ =0x000001FF
	ands r1, r0
	ands r2, r0
	cmp r3, #0x01
	beq _0800551C
	cmp r3, #0x01
	bcc _0800550C
	cmp r3, #0x02
	beq _0800552C
	cmp r3, #0x03
	beq _0800553C
	b _08005544
	.byte 0x00, 0x00
_08005508: .4byte 0x000001FF
_0800550C:
	ldr r0, _08005514 @ =0x03007544
	strh r1, [r0, #0x00]
	ldr r0, _08005518 @ =0x030074FC
	b _08005542
_08005514: .4byte 0x03007544
_08005518: .4byte 0x030074FC
_0800551C:
	ldr r0, _08005524 @ =0x03007538
	strh r1, [r0, #0x00]
	ldr r0, _08005528 @ =0x03007558
	b _08005542
_08005524: .4byte 0x03007538
_08005528: .4byte 0x03007558
_0800552C:
	ldr r0, _08005534 @ =0x03007520
	strh r1, [r0, #0x00]
	ldr r0, _08005538 @ =0x03007534
	b _08005542
_08005534: .4byte 0x03007520
_08005538: .4byte 0x03007534
_0800553C:
	ldr r0, _08005548 @ =0x0300755C
	strh r1, [r0, #0x00]
	ldr r0, _0800554C @ =0x030074E4
_08005542:
	strh r2, [r0, #0x00]
_08005544:
	bx lr
	.byte 0x00, 0x00
_08005548: .4byte 0x0300755C
_0800554C: .4byte 0x030074E4
.syntax divided
