.syntax unified
	.align 2, 0
	.global func_0807C2EC
	.thumb
	.thumb_func
	.type func_0807C2EC, %function
func_0807C2EC: @ 0807C2EC
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r0, #0xA1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x06
	beq _0807C334
	adds r0, r4, #0x0
	bl func_0807CE68
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0807C31E
	ldr r0, [r4, #0x78]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0x00
	beq _0807C334
	adds r0, r4, #0x0
	bl func_0807C39C
	ldr r0, [r4, #0x78]
	movs r1, #0x81
	negs r1, r1
	ands r0, r1
	b _0807C332
_0807C31E:
	ldr r0, [r4, #0x78]
	movs r5, #0x80
	ands r0, r5
	cmp r0, #0x00
	bne _0807C334
	adds r0, r4, #0x0
	bl func_0807C33C
	ldr r0, [r4, #0x78]
	orrs r0, r5
_0807C332:
	str r0, [r4, #0x78]
_0807C334:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
