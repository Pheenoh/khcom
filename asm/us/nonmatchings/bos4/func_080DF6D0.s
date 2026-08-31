.syntax unified
	.align 2, 0
	.global func_080DF6D0
	.thumb
	.thumb_func
	.type func_080DF6D0, %function
func_080DF6D0: @ 080DF6D0
	push {r4, lr}
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl func_080DEE18
	adds r4, r0, #0x0
	ldrh r1, [r4, #0x00]
	movs r0, #0x02
	orrs r0, r1
	strh r0, [r4, #0x00]
	ldr r0, [r4, #0x04]
	bl SeedRandom
	ldr r2, _080DF720 @ =0x0203C7AC
	ldr r1, [r2, #0x00]
	ldrb r0, [r4, #0x08]
	strb r0, [r1, #0x0C]
	ldr r1, [r2, #0x00]
	ldrb r0, [r4, #0x09]
	strb r0, [r1, #0x0D]
	ldr r0, _080DF724 @ =0x0203C584
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080DF71A
	ldrb r2, [r4, #0x09]
	lsls r2, r2, #0x03
	ldr r0, _080DF728 @ =0x0984D134
	adds r2, r2, r0
	ldr r0, _080DF72C @ =0x02039BB0
	movs r1, #0xDC
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldrb r1, [r2, #0x05]
	str r1, [r0, #0x00]
	ldrb r0, [r2, #0x00]
	bl func_080E5510
_080DF71A:
	pop {r4}
	pop {r0}
	bx r0
_080DF720: .4byte 0x0203C7AC
_080DF724: .4byte 0x0203C584
_080DF728: .4byte 0x0984D134
_080DF72C: .4byte 0x02039BB0
.syntax divided
