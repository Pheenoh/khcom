.syntax unified
	.align 2, 0
	.global func_08005A64
	.thumb
	.thumb_func
	.type func_08005A64, %function
func_08005A64: @ 08005A64
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	bl func_08005AFC
	adds r6, r0, #0x0
	ldr r2, [r4, #0x14]
	cmp r2, #0x00
	bne _08005A78
	movs r0, #0x00
	b _08005ABC
_08005A78:
	ldrh r0, [r4, #0x0A]
	adds r0, #0x01
	movs r5, #0x00
	strh r0, [r4, #0x0A]
	ldrh r3, [r4, #0x0E]
	lsls r1, r3, #0x02
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1, #0x02]
	cmp r0, r1
	bcc _08005ABA
	adds r0, r3, #0x1
	strh r0, [r4, #0x0E]
	strh r5, [r4, #0x0A]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #0x0C]
	cmp r0, r1
	bcc _08005ABA
	ldrh r1, [r4, #0x08]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08005AAE
	strh r5, [r4, #0x0E]
	b _08005AB0
_08005AAE:
	strh r3, [r4, #0x0E]
_08005AB0:
	movs r2, #0x80
	lsls r2, r2, #0x05
	adds r0, r2, #0x0
	orrs r0, r1
	strh r0, [r4, #0x08]
_08005ABA:
	adds r0, r6, #0x0
_08005ABC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
