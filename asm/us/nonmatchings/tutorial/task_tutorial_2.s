.syntax unified
	.align 2, 0
	.global task_tutorial_2
	.thumb
	.thumb_func
	.type task_tutorial_2, %function
task_tutorial_2: @ 0805E788
	push {r4, r5, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldrh r1, [r4, #0x00]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _0805E812
	adds r0, r4, #0x0
	adds r0, #0x20
	bl func_08005A64
	adds r5, r0, #0x0
	ldrh r0, [r4, #0x30]
	cmp r0, #0x00
	bne _0805E7D4
	ldrh r3, [r4, #0x12]
	ldr r2, _0805E7CC @ =0x08121400
	ldr r0, _0805E7D0 @ =0x03007480
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x03
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	asrs r0, r0, #0x07
	ldrh r1, [r4, #0x14]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0805E7F4
	.byte 0x00, 0x00
_0805E7CC: .4byte 0x08121400
_0805E7D0: .4byte 0x03007480
_0805E7D4:
	ldr r2, _0805E81C @ =0x08121400
	ldr r0, _0805E820 @ =0x03007480
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x03
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	asrs r0, r0, #0x07
	ldrh r1, [r4, #0x12]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r1, [r4, #0x14]
_0805E7F4:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, [r4, #0x18]
	ldr r2, [r4, #0x1C]
	str r2, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r2, #0x10
	str r2, [sp, #0x008]
	str r4, [sp, #0x00C]
	adds r2, r5, #0x0
	bl func_080023E0
_0805E812:
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805E81C: .4byte 0x08121400
_0805E820: .4byte 0x03007480
.syntax divided
