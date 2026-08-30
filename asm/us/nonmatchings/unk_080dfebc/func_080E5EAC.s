.syntax unified
	.align 2, 0
	.global func_080E5EAC
	.thumb
	.thumb_func
	.type func_080E5EAC, %function
func_080E5EAC: @ 080E5EAC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	ldr r6, _080E5F14 @ =0x02039BB0
	ldr r0, [r6, #0x08]
	movs r4, #0x02
	orrs r0, r4
	str r0, [r6, #0x08]
	adds r0, r5, #0x0
	adds r0, #0x48
	movs r1, #0x01
	bl func_08012614
	ldr r7, _080E5F18 @ =0x0203C7AC
	ldr r1, [r7, #0x00]
	ldr r0, [r1, #0x00]
	orrs r0, r4
	str r0, [r1, #0x00]
	ldr r0, _080E5F1C @ =0x02039BA0
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x70]
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2, #0x70]
	ldrh r1, [r5, #0x04]
	movs r0, #0x04
	orrs r0, r1
	strh r0, [r5, #0x04]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0x00
	beq _080E5EF2
	ldr r0, [r6, #0x08]
	movs r1, #0x04
	orrs r0, r1
	str r0, [r6, #0x08]
_080E5EF2:
	ldrh r1, [r5, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080E5F20
	bl func_080065A4
	ldr r4, [r7, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl __umodsi3
	adds r0, #0x80
	strb r0, [r4, #0x0E]
	b _080E5F48
_080E5F14: .4byte 0x02039BB0
_080E5F18: .4byte 0x0203C7AC
_080E5F1C: .4byte 0x02039BA0
_080E5F20:
	movs r0, #0x80
	lsls r0, r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080E5F40
	bl func_080065A4
	ldr r4, [r7, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl __umodsi3
	adds r0, #0x83
	strb r0, [r4, #0x0E]
	b _080E5F48
_080E5F40:
	bl func_080E5E44
	ldr r1, [r7, #0x00]
	strb r0, [r1, #0x0E]
_080E5F48:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
