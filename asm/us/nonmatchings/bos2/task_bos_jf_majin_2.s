.syntax unified
	.align 2, 0
	.global task_bos_jf_majin_2
	.thumb
	.thumb_func
	.type task_bos_jf_majin_2, %function
task_bos_jf_majin_2: @ 080BE7B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r5, [r6, #0x00]
	ldr r0, _080BE7F8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080BE804
	movs r1, #0x93
	lsls r1, r1, #0x02
	adds r0, r5, r1
	ldrh r1, [r0, #0x00]
	movs r2, #0x01
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080BE810
	ldr r0, _080BE7FC @ =0x03007480
	ldr r0, [r0, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _080BE804
	ldr r0, _080BE800 @ =0x08F69BC4
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x20
	bl func_08007E00
	ldr r7, [r6, #0x0C]
	b _080BE812
_080BE7F8: .4byte 0x02039B84
_080BE7FC: .4byte 0x03007480
_080BE800: .4byte 0x08F69BC4
_080BE804:
	ldr r0, _080BE86C @ =0x096FB584
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x20
	bl func_08007E00
_080BE810:
	ldr r7, [r6, #0x08]
_080BE812:
	ldr r0, _080BE870 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r1, [r3, #0x00]
	ldr r0, [r5, #0x04]
	subs r1, r1, r0
	asrs r1, r1, #0x08
	movs r4, #0xC2
	lsls r4, r4, #0x02
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	adds r0, r0, r2
	ldr r2, [r3, #0x04]
	subs r2, r2, r0
	asrs r2, r2, #0x08
	movs r0, #0x93
	lsls r0, r0, #0x01
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_08005244
	adds r0, r6, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080BE8D4
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080BE874
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	b _080BE886
_080BE86C: .4byte 0x096FB584
_080BE870: .4byte 0x02039B84
_080BE874:
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	orrs r1, r0
	lsrs r1, r1, #0x10
	mov r8, r1
_080BE886:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r1, r6, #0x0
	adds r1, #0x40
	ldrh r1, [r1, #0x00]
	subs r1, #0x3D
	ldrh r4, [r4, #0x00]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r6, #0x10]
	ldr r3, [r6, #0x04]
	str r7, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r5, [r5, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _080BE8E8 @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
_080BE8D4:
	adds r0, r6, #0x0
	adds r0, #0x6C
	bl TaskPoolDraw
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080BE8E8: .4byte 0xFFFFEFFC
.syntax divided
