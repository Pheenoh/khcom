.syntax unified
	.align 2, 0
	.global task_btl_area_2
	.thumb
	.thumb_func
	.type task_btl_area_2, %function
task_btl_area_2: @ 0801D68C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	ldrb r0, [r7, #0x08]
	cmp r0, #0x00
	bne _0801D6A2
	b _0801DBFE
_0801D6A2:
	movs r0, #0x12
	add r0, sp
	mov r8, r0
	ldr r6, _0801DA74 @ =0x02039B84
	ldr r4, [r6, #0x00]
	adds r1, r4, #0x0
	adds r1, #0xB8
	adds r0, r4, #0x0
	adds r0, #0xC4
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x08
	ldr r2, [r1, #0x00]
	subs r2, r2, r0
	adds r1, #0x04
	adds r0, r4, #0x0
	adds r0, #0xC6
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x08
	ldr r3, [r1, #0x00]
	subs r3, r3, r0
	adds r0, r4, #0x0
	adds r0, #0xC0
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r4, #0x00
	ldsh r0, [r0, r4]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _0801DA78 @ =0x00000101
	str r4, [sp, #0x00C]
	ldr r2, _0801DA7C @ =0x08B1E974
	bl DrawSprite
	ldr r4, [r6, #0x00]
	adds r1, r4, #0x0
	adds r1, #0xB8
	adds r0, r4, #0x0
	adds r0, #0xC4
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x08
	ldr r2, [r1, #0x00]
	adds r2, r2, r0
	adds r1, #0x04
	adds r0, r4, #0x0
	adds r0, #0xC6
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x08
	ldr r3, [r1, #0x00]
	subs r3, r3, r0
	adds r0, r4, #0x0
	adds r0, #0xC0
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r4, #0x00
	ldsh r0, [r0, r4]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _0801DA78 @ =0x00000101
	str r4, [sp, #0x00C]
	ldr r2, _0801DA80 @ =0x08B1E97E
	bl DrawSprite
	ldr r4, [r6, #0x00]
	adds r1, r4, #0x0
	adds r1, #0xB8
	adds r0, r4, #0x0
	adds r0, #0xC4
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x08
	ldr r2, [r1, #0x00]
	subs r2, r2, r0
	adds r1, #0x04
	adds r0, r4, #0x0
	adds r0, #0xC6
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x08
	ldr r3, [r1, #0x00]
	adds r3, r3, r0
	adds r0, r4, #0x0
	adds r0, #0xC0
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r4, #0x00
	ldsh r0, [r0, r4]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _0801DA78 @ =0x00000101
	str r4, [sp, #0x00C]
	ldr r2, _0801DA84 @ =0x08B1E992
	bl DrawSprite
	ldr r4, [r6, #0x00]
	adds r1, r4, #0x0
	adds r1, #0xB8
	adds r0, r4, #0x0
	adds r0, #0xC4
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x08
	ldr r2, [r1, #0x00]
	adds r2, r2, r0
	adds r1, #0x04
	adds r0, r4, #0x0
	adds r0, #0xC6
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x08
	ldr r3, [r1, #0x00]
	adds r3, r3, r0
	adds r0, r4, #0x0
	adds r0, #0xC0
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r4, #0x00
	ldsh r0, [r0, r4]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _0801DA78 @ =0x00000101
	str r4, [sp, #0x00C]
	ldr r2, _0801DA88 @ =0x08B1E988
	bl DrawSprite
	ldr r1, [r6, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xB8
	ldr r2, [r0, #0x00]
	adds r0, #0x04
	ldr r3, [r0, #0x00]
	adds r0, #0x04
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	str r4, [sp, #0x00C]
	ldr r2, _0801DA8C @ =0x08B1E9A6
	bl DrawSprite
	ldr r1, [r6, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xB8
	ldr r2, [r0, #0x00]
	adds r0, #0x04
	ldr r3, [r0, #0x00]
	movs r4, #0xC0
	adds r4, r4, r1
	mov r9, r4
	adds r0, #0x0C
	movs r4, #0x00
	ldsh r1, [r0, r4]
	lsls r1, r1, #0x08
	mov r4, r9
	ldr r0, [r4, #0x00]
	subs r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r4, _0801DA90 @ =0x08B1E99C
	mov r10, r4
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r2, _0801DA78 @ =0x00000101
	str r2, [sp, #0x00C]
	mov r2, r10
	bl DrawSprite
	ldr r1, [r6, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xB8
	ldr r2, [r0, #0x00]
	adds r0, #0x04
	ldr r3, [r0, #0x00]
	movs r4, #0xC0
	adds r4, r4, r1
	mov r9, r4
	adds r0, #0x0C
	movs r4, #0x00
	ldsh r1, [r0, r4]
	lsls r1, r1, #0x08
	mov r4, r9
	ldr r0, [r4, #0x00]
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r2, #0x02
	str r2, [sp, #0x008]
	ldr r4, _0801DA78 @ =0x00000101
	str r4, [sp, #0x00C]
	mov r2, r10
	bl DrawSprite
	ldr r4, [r6, #0x00]
	adds r0, r4, #0x0
	adds r0, #0xA4
	ldrb r6, [r0, #0x00]
	cmp r6, #0x00
	bne _0801D8DC
	b _0801DA94
_0801D8DC:
	subs r0, #0x24
	bl func_08000C8C
	adds r5, r0, #0x0
	cmp r5, #0x00
	bne _0801D8EA
	b _0801DBFE
_0801D8EA:
	mov r9, r8
	add r0, sp, #0x010
	mov r10, r0
	movs r1, #0x00
	mov r8, r1
_0801D8F4:
	adds r6, r5, #0x0
	adds r6, #0x9E
	ldrh r0, [r6, #0x00]
	lsls r0, r0, #0x08
	ldr r2, [r5, #0x04]
	subs r2, r2, r0
	adds r4, r5, #0x0
	adds r4, #0xA0
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x08
	ldr r3, [r5, #0x08]
	subs r3, r3, r0
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r9
	bl WorldToScreen
	mov r2, r10
	movs r3, #0x00
	ldsh r0, [r2, r3]
	mov r2, r9
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	mov r2, r8
	str r2, [sp, #0x004]
	str r2, [sp, #0x008]
	ldr r2, _0801DA78 @ =0x00000101
	str r2, [sp, #0x00C]
	ldr r2, _0801DA7C @ =0x08B1E974
	bl DrawSprite
	ldrh r0, [r6, #0x00]
	lsls r0, r0, #0x08
	ldr r2, [r5, #0x04]
	adds r2, r2, r0
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x08
	ldr r3, [r5, #0x08]
	subs r3, r3, r0
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r9
	bl WorldToScreen
	mov r3, r10
	movs r1, #0x00
	ldsh r0, [r3, r1]
	mov r2, r9
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	mov r2, r8
	str r2, [sp, #0x004]
	str r2, [sp, #0x008]
	ldr r2, _0801DA78 @ =0x00000101
	str r2, [sp, #0x00C]
	ldr r2, _0801DA80 @ =0x08B1E97E
	bl DrawSprite
	ldrh r0, [r6, #0x00]
	lsls r0, r0, #0x08
	ldr r2, [r5, #0x04]
	subs r2, r2, r0
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x08
	ldr r3, [r5, #0x08]
	adds r3, r3, r0
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r9
	bl WorldToScreen
	mov r3, r10
	movs r1, #0x00
	ldsh r0, [r3, r1]
	mov r2, r9
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	mov r2, r8
	str r2, [sp, #0x004]
	str r2, [sp, #0x008]
	ldr r2, _0801DA78 @ =0x00000101
	str r2, [sp, #0x00C]
	ldr r2, _0801DA84 @ =0x08B1E992
	bl DrawSprite
	ldrh r0, [r6, #0x00]
	lsls r0, r0, #0x08
	ldr r2, [r5, #0x04]
	adds r2, r2, r0
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x08
	ldr r3, [r5, #0x08]
	adds r3, r3, r0
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r9
	bl WorldToScreen
	mov r3, r10
	movs r4, #0x00
	ldsh r0, [r3, r4]
	mov r2, r9
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r2, _0801DA78 @ =0x00000101
	str r2, [sp, #0x00C]
	ldr r2, _0801DA88 @ =0x08B1E988
	bl DrawSprite
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r9
	bl WorldToScreen
	mov r3, r10
	movs r4, #0x00
	ldsh r0, [r3, r4]
	mov r2, r9
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r2, _0801DA78 @ =0x00000101
	str r2, [sp, #0x00C]
	ldr r2, _0801DA8C @ =0x08B1E9A6
	bl DrawSprite
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	adds r0, r5, #0x0
	adds r0, #0x9C
	ldrh r1, [r0, #0x00]
	lsls r1, r1, #0x08
	ldr r0, [r5, #0x0C]
	subs r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r9
	bl WorldToScreen
	mov r3, r10
	movs r4, #0x00
	ldsh r0, [r3, r4]
	mov r2, r9
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r2, _0801DA78 @ =0x00000101
	str r2, [sp, #0x00C]
	ldr r2, _0801DA90 @ =0x08B1E99C
	bl DrawSprite
	adds r0, r5, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r5, r0, #0x0
	cmp r5, #0x00
	beq _0801DA72
	b _0801D8F4
_0801DA72:
	b _0801DBFE
_0801DA74: .4byte 0x02039B84
_0801DA78: .4byte 0x00000101
_0801DA7C: .4byte 0x08B1E974
_0801DA80: .4byte 0x08B1E97E
_0801DA84: .4byte 0x08B1E992
_0801DA88: .4byte 0x08B1E988
_0801DA8C: .4byte 0x08B1E9A6
_0801DA90: .4byte 0x08B1E99C
_0801DA94:
	ldr r5, [r4, #0x7C]
	movs r3, #0x9E
	adds r3, r3, r5
	mov r9, r3
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x08
	ldr r2, [r5, #0x04]
	subs r2, r2, r0
	adds r4, r5, #0x0
	adds r4, #0xA0
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x08
	ldr r3, [r5, #0x08]
	subs r3, r3, r0
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r2, _0801DC10 @ =0x00000101
	str r2, [sp, #0x00C]
	ldr r2, _0801DC14 @ =0x08B1E974
	bl DrawSprite
	mov r3, r9
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x08
	ldr r2, [r5, #0x04]
	adds r2, r2, r0
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x08
	ldr r3, [r5, #0x08]
	subs r3, r3, r0
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r2, _0801DC10 @ =0x00000101
	str r2, [sp, #0x00C]
	ldr r2, _0801DC18 @ =0x08B1E97E
	bl DrawSprite
	mov r3, r9
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x08
	ldr r2, [r5, #0x04]
	subs r2, r2, r0
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x08
	ldr r3, [r5, #0x08]
	adds r3, r3, r0
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r2, _0801DC10 @ =0x00000101
	str r2, [sp, #0x00C]
	ldr r2, _0801DC1C @ =0x08B1E992
	bl DrawSprite
	mov r3, r9
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x08
	ldr r2, [r5, #0x04]
	adds r2, r2, r0
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x08
	ldr r3, [r5, #0x08]
	adds r3, r3, r0
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r4, #0x00
	ldsh r0, [r0, r4]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r4, _0801DC10 @ =0x00000101
	str r4, [sp, #0x00C]
	ldr r2, _0801DC20 @ =0x08B1E988
	bl DrawSprite
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	str r4, [sp, #0x00C]
	ldr r2, _0801DC24 @ =0x08B1E9A6
	bl DrawSprite
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	adds r0, r5, #0x0
	adds r0, #0x9C
	ldrh r1, [r0, #0x00]
	lsls r1, r1, #0x08
	ldr r0, [r5, #0x0C]
	subs r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	add r0, sp, #0x010
	movs r4, #0x00
	ldsh r0, [r0, r4]
	mov r2, r8
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r4, _0801DC10 @ =0x00000101
	str r4, [sp, #0x00C]
	mov r2, r10
	bl DrawSprite
_0801DBFE:
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801DC10: .4byte 0x00000101
_0801DC14: .4byte 0x08B1E974
_0801DC18: .4byte 0x08B1E97E
_0801DC1C: .4byte 0x08B1E992
_0801DC20: .4byte 0x08B1E988
_0801DC24: .4byte 0x08B1E9A6
.syntax divided
