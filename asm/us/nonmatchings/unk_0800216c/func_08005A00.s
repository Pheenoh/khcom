.syntax unified
	.align 2, 0
	.global func_08005A00
	.thumb
	.thumb_func
	.type func_08005A00, %function
func_08005A00: @ 08005A00
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldrh r0, [r4, #0x10]
	cmp r0, r6
	beq _08005A5C
	ldr r0, [r4, #0x00]
	lsls r1, r6, #0x02
	adds r1, r1, r0
	ldr r1, [r1, #0x00]
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x0C]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	bne _08005A2A
	str r0, [r4, #0x14]
	b _08005A5C
_08005A2A:
	adds r0, r1, #0x6
	str r0, [r4, #0x14]
	movs r0, #0x04
	ands r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	bne _08005A58
	strh r0, [r4, #0x0A]
	movs r0, #0x02
	ands r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _08005A56
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #0x0C]
	bl func_0811D7CC
_08005A56:
	strh r0, [r4, #0x0E]
_08005A58:
	strh r5, [r4, #0x08]
	strh r6, [r4, #0x10]
_08005A5C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
