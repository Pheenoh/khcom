.syntax unified
	.align 2, 0
	.global task_bos_boogie_kaihuku_1
	.thumb
	.thumb_func
	.type task_bos_boogie_kaihuku_1, %function
task_bos_boogie_kaihuku_1: @ 080DB758
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x40
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	adds r6, r0, #0x0
	adds r6, #0x40
	adds r0, r5, #0x0
	bl func_0801ADAC
	subs r0, #0x01
	cmp r0, #0x07
	bhi _080DB7AE
	lsls r0, r0, #0x02
	ldr r1, _080DB784 @ =0x080DB788
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_080DB784: .4byte 0x080DB788
	.byte 0xBE, 0xB7, 0x0D, 0x08, 0xAE, 0xB7, 0x0D, 0x08, 0xBE, 0xB7, 0x0D, 0x08, 0xBE, 0xB7, 0x0D, 0x08
	.byte 0xA8, 0xB7, 0x0D, 0x08, 0xBE, 0xB7, 0x0D, 0x08, 0xBE, 0xB7, 0x0D, 0x08, 0xBE, 0xB7, 0x0D, 0x08
	.byte 0x00, 0x20, 0x20, 0x60, 0x0D, 0xE0
_080DB7AE:
	movs r0, #0x00
	bl func_0801C1C0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DB7CC
	bl func_080D9A58
	ldr r0, [r4, #0x00]
	cmp r0, #0x01
	beq _080DB7CC
	movs r0, #0x01
	str r0, [r4, #0x00]
	movs r0, #0x00
	strh r0, [r4, #0x04]
_080DB7CC:
	ldr r1, [r4, #0x00]
	cmp r1, #0x01
	beq _080DB864
	cmp r1, #0x01
	bcc _080DB7DC
	cmp r1, #0x02
	beq _080DB8A8
	b _080DB8B6
_080DB7DC:
	ldr r0, [r5, #0x04]
	ldr r1, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	adds r1, r1, r2
	bl func_0802F274
	movs r2, #0x04
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	bne _080DB818
	ldr r0, [r5, #0x04]
	ldr r1, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	movs r3, #0xA0
	lsls r3, r3, #0x06
	adds r2, r2, r3
	ldr r3, _080DB810 @ =0x00000199
	bl func_08015228
	ldr r0, _080DB814 @ =0x00000256
	bl m4aSongNumStart
	ldrh r0, [r4, #0x04]
	adds r0, #0x01
	b _080DB8B4
	.byte 0x00, 0x00
_080DB810: .4byte 0x00000199
_080DB814: .4byte 0x00000256
_080DB818:
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DB8B6
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl func_08019190
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r2, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x6C
	adds r0, #0x6E
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x00
	bge _080DB842
	adds r0, #0x0F
_080DB842:
	asrs r0, r0, #0x04
	ldrh r4, [r1, #0x00]
	adds r0, r0, r4
	strh r0, [r1, #0x00]
	ldr r0, [r2, #0x00]
	adds r2, r0, #0x0
	adds r2, #0x6C
	adds r0, #0x6E
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldrh r3, [r0, #0x00]
	movs r4, #0x00
	ldsh r0, [r0, r4]
	cmp r1, r0
	ble _080DB874
	strh r3, [r2, #0x00]
	b _080DB874
_080DB864:
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _080DB87C
	ldr r0, _080DB878 @ =0x0203C570
	strb r1, [r0, #0x00]
	adds r0, r5, #0x0
	bl func_0801AF08
_080DB874:
	movs r0, #0x00
	b _080DB8CE
_080DB878: .4byte 0x0203C570
_080DB87C:
	ldrh r0, [r4, #0x04]
	adds r0, #0x01
	strh r0, [r4, #0x04]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r5, #0x0C]
	ldr r1, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	ldr r0, [r2, #0x00]
	adds r0, #0x42
	str r0, [r2, #0x00]
	ldr r1, [r5, #0x0C]
	ldr r0, _080DB8A4 @ =0xFFFFE000
	cmp r1, r0
	bge _080DB8B6
	movs r0, #0x00
	str r0, [r5, #0x0C]
	b _080DB8B6
_080DB8A4: .4byte 0xFFFFE000
_080DB8A8:
	ldrh r1, [r4, #0x04]
	movs r2, #0x04
	ldsh r0, [r4, r2]
	cmp r0, #0x1E
	bgt _080DB874
	adds r0, r1, #0x1
_080DB8B4:
	strh r0, [r4, #0x04]
_080DB8B6:
	adds r0, r4, #0x0
	adds r0, #0x14
	bl AnimUpdate
	adds r0, r5, #0x0
	adds r0, #0x40
	ldr r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	bl func_08012324
	movs r0, #0x01
_080DB8CE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
