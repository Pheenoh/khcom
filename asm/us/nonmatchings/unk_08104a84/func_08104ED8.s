.syntax unified
	.align 2, 0
	.global func_08104ED8
	.thumb
	.thumb_func
	.type func_08104ED8, %function
func_08104ED8: @ 08104ED8
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08104F20 @ =0x02035C10
	movs r1, #0x34
	muls r1, r0
	ldr r0, [r2, #0x00]
	adds r4, r0, r1
	ldrh r0, [r4, #0x00]
	cmp r0, #0x8F
	beq _08104F24
	bl func_08104EB4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x0E
	adds r1, r4, #0x0
	adds r1, #0x08
	adds r1, r1, r0
	ldrh r2, [r1, #0x00]
	adds r1, r2, #0x0
	adds r0, r4, #0x0
	adds r0, #0x2E
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08104F14
	movs r1, #0x80
	lsls r1, r1, #0x08
	adds r0, r1, #0x0
	adds r1, r0, #0x0
	orrs r1, r2
_08104F14:
	adds r0, r1, #0x0
	bl func_08060A2C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _08104F26
_08104F20: .4byte 0x02035C10
_08104F24:
	movs r0, #0x00
_08104F26:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
