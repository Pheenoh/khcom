.syntax unified
	.align 2, 0
	.global func_080C61D4
	.thumb
	.thumb_func
	.type func_080C61D4, %function
func_080C61D4: @ 080C61D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r6, _080C6280 @ =0x0203AAC0
	ldr r0, _080C6284 @ =0x0203AA10
	mov r8, r0
	ldr r3, _080C6288 @ =0x02039BB0
	ldrh r0, [r3, #0x32]
	movs r2, #0x00
	strh r0, [r6, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xF8
	ldrh r0, [r0, #0x00]
	strh r0, [r6, #0x02]
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldrb r0, [r0, #0x00]
	strh r0, [r6, #0x04]
	ldr r0, _080C628C @ =0x0203A9EC
	ldrh r0, [r0, #0x00]
	strh r0, [r6, #0x06]
	ldr r0, _080C6290 @ =0x0203A9F0
	ldrh r0, [r0, #0x00]
	strh r0, [r6, #0x08]
	adds r0, r3, #0x0
	adds r0, #0xFE
	ldrh r0, [r0, #0x00]
	strh r0, [r6, #0x0A]
	adds r1, #0x04
	adds r0, r3, r1
	ldr r1, [r0, #0x04]
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x0C]
	str r1, [r6, #0x10]
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldr r1, [r0, #0x04]
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x14]
	str r1, [r6, #0x18]
	strh r2, [r6, #0x1C]
	mov r12, r6
	ldr r7, _080C6294 @ =0x02039828
	adds r4, r6, #0x0
	movs r0, #0xC3
	lsls r0, r0, #0x01
	adds r2, r3, r0
	movs r5, #0x01
	movs r3, #0x0C
_080C623A:
	ldrb r0, [r2, #0x00]
	subs r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x0B
	bhi _080C6252
	adds r0, r5, #0x0
	ldrb r1, [r2, #0x00]
	lsls r0, r1
	ldrh r1, [r4, #0x1C]
	orrs r0, r1
	strh r0, [r4, #0x1C]
_080C6252:
	adds r2, #0x04
	subs r3, #0x01
	cmp r3, #0x00
	bge _080C623A
	ldr r0, [r7, #0x00]
	cmp r0, #0x00
	bne _080C62A0
	ldr r0, _080C6298 @ =0x03007480
	ldr r0, [r0, #0x00]
	ldr r4, _080C629C @ =0x0000FFFF
	ands r0, r4
	bl SeedRandom
	bl GetRandom
	ldr r5, _080C6280 @ =0x0203AAC0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl __umodsi3
	strh r0, [r5, #0x1E]
	b _080C62A6
_080C6280: .4byte 0x0203AAC0
_080C6284: .4byte 0x0203AA10
_080C6288: .4byte 0x02039BB0
_080C628C: .4byte 0x0203A9EC
_080C6290: .4byte 0x0203A9F0
_080C6294: .4byte 0x02039828
_080C6298: .4byte 0x03007480
_080C629C: .4byte 0x0000FFFF
_080C62A0:
	movs r0, #0x00
	mov r1, r12
	strh r0, [r1, #0x1E]
_080C62A6:
	ldr r1, _080C62D4 @ =0x0203C378
	movs r0, #0x0B
	strh r0, [r1, #0x00]
	ldr r1, _080C62D8 @ =0x0203C394
	movs r0, #0x01
	strh r0, [r1, #0x00]
	ldr r0, _080C62DC @ =0x0203C3A4
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r0, _080C62E0 @ =0x0203C380
	strb r1, [r0, #0x00]
	ldr r0, _080C62E4 @ =0x0203C384
	strb r1, [r0, #0x00]
	ldr r0, _080C62E8 @ =0x0203C390
	str r6, [r0, #0x00]
	ldr r0, _080C62EC @ =0x0203C39C
	mov r1, r8
	str r1, [r0, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080C62D4: .4byte 0x0203C378
_080C62D8: .4byte 0x0203C394
_080C62DC: .4byte 0x0203C3A4
_080C62E0: .4byte 0x0203C380
_080C62E4: .4byte 0x0203C384
_080C62E8: .4byte 0x0203C390
_080C62EC: .4byte 0x0203C39C
.syntax divided
