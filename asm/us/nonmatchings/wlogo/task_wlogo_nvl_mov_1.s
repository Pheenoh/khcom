.syntax unified
	.align 2, 0
	.global task_wlogo_nvl_mov_1
	.thumb
	.thumb_func
	.type task_wlogo_nvl_mov_1, %function
task_wlogo_nvl_mov_1: @ 080B573C
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldrb r4, [r5, #0x18]
	cmp r4, #0x00
	beq _080B574A
	b _080B5880
_080B574A:
	ldr r0, [r5, #0x00]
	ldr r2, [r5, #0x08]
	adds r0, r0, r2
	str r0, [r5, #0x00]
	ldr r0, [r5, #0x04]
	ldr r1, [r5, #0x0C]
	adds r0, r0, r1
	str r0, [r5, #0x04]
	ldr r0, [r5, #0x10]
	adds r2, r2, r0
	str r2, [r5, #0x08]
	ldr r0, [r5, #0x14]
	adds r1, r1, r0
	str r1, [r5, #0x0C]
	ldrh r1, [r5, #0x1A]
	adds r1, #0x01
	strh r1, [r5, #0x1A]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080B586C @ =0x096198D4
	ldrh r2, [r5, #0x1C]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	adds r2, r0, r3
	movs r6, #0x00
	ldsh r0, [r2, r6]
	cmp r1, r0
	blt _080B57E6
	strh r4, [r5, #0x1A]
	ldrb r0, [r2, #0x14]
	cmp r0, #0x01
	bne _080B579A
	adds r1, r5, #0x0
	adds r1, #0x49
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldrb r0, [r5, #0x18]
	adds r0, #0x01
	strb r0, [r5, #0x18]
_080B579A:
	ldrh r0, [r5, #0x1C]
	adds r0, #0x01
	strh r0, [r5, #0x1C]
	ldrh r1, [r5, #0x1C]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r3, #0x4
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x08]
	ldrh r1, [r5, #0x1C]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r3, #0x0
	adds r1, #0x08
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x0C]
	ldrh r1, [r5, #0x1C]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r3, #0x0
	adds r1, #0x0C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x10]
	ldrh r1, [r5, #0x1C]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r3, #0x0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x14]
_080B57E6:
	ldrh r0, [r5, #0x1E]
	movs r1, #0x05
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080B5816
	ldr r0, [r5, #0x00]
	str r0, [sp, #0x004]
	ldr r0, [r5, #0x04]
	str r0, [sp, #0x008]
	adds r4, r5, #0x0
	adds r4, #0x20
	ldrb r0, [r4, #0x00]
	str r0, [sp, #0x00C]
	ldr r0, _080B5870 @ =0x02034C68
	ldr r1, _080B5874 @ =0x09EF18BC
	add r2, sp, #0x004
	bl func_08000E14
	ldrb r1, [r4, #0x00]
	movs r0, #0x01
	subs r0, r0, r1
	strb r0, [r4, #0x00]
_080B5816:
	adds r4, r5, #0x0
	adds r4, #0x30
	adds r0, r4, #0x0
	bl func_08005A64
	str r0, [r5, #0x2C]
	ldrh r0, [r5, #0x1E]
	cmp r0, #0x28
	bne _080B5838
	ldr r3, _080B5878 @ =0x09EF35A4
	ldr r0, _080B587C @ =0x09EF3574
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x00
	bl func_08005974
_080B5838:
	ldrh r0, [r5, #0x1E]
	cmp r0, #0x37
	bne _080B584E
	ldr r3, _080B5878 @ =0x09EF35A4
	ldr r0, _080B587C @ =0x09EF3574
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	movs r1, #0x04
	movs r2, #0x00
	bl func_08005974
_080B584E:
	ldrh r0, [r5, #0x1E]
	cmp r0, #0x4B
	bne _080B5864
	ldr r3, _080B5878 @ =0x09EF35A4
	ldr r0, _080B587C @ =0x09EF3574
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x00
	bl func_08005974
_080B5864:
	ldrh r0, [r5, #0x1E]
	adds r0, #0x01
	strh r0, [r5, #0x1E]
	b _080B5892
_080B586C: .4byte 0x096198D4
_080B5870: .4byte 0x02034C68
_080B5874: .4byte 0x09EF18BC
_080B5878: .4byte 0x09EF35A4
_080B587C: .4byte 0x09EF3574
_080B5880:
	ldrh r0, [r5, #0x1A]
	adds r0, #0x01
	strh r0, [r5, #0x1A]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bls _080B5892
	movs r0, #0x00
	b _080B58A2
_080B5892:
	ldr r4, _080B58AC @ =0x02034C68
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
	movs r0, #0x01
_080B58A2:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080B58AC: .4byte 0x02034C68
.syntax divided
