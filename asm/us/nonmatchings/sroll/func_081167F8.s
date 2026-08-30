.syntax unified
	.align 2, 0
	.global func_081167F8
	.thumb
	.thumb_func
	.type func_081167F8, %function
func_081167F8: @ 081167F8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	b _0811682E
_08116800:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0x00
	beq _0811681A
	ldrb r0, [r4, #0x00]
	lsls r0, r0, #0x08
	ldrb r1, [r4, #0x01]
	orrs r1, r0
	adds r0, r5, #0x0
	bl func_081161EC
	adds r4, #0x02
	b _0811682E
_0811681A:
	ldrb r0, [r4, #0x00]
	bl func_08116CDC
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0x0
	bl func_081161EC
	adds r4, #0x01
_0811682E:
	ldrb r1, [r4, #0x00]
	cmp r1, #0x00
	bne _08116800
	adds r0, r4, #0x1
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
