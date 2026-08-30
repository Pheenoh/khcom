.syntax unified
	.align 2, 0
	.global task_hum_hook_bomb_0
	.thumb
	.thumb_func
	.type task_hum_hook_bomb_0, %function
task_hum_hook_bomb_0: @ 0804CB40
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	movs r0, #0x12
	ldsh r1, [r6, r0]
	cmp r1, #0x00
	beq _0804CB58
	adds r1, r5, #0x0
	adds r1, #0x2C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _0804CB5E
_0804CB58:
	adds r0, r5, #0x0
	adds r0, #0x2C
	strb r1, [r0, #0x00]
_0804CB5E:
	ldr r0, _0804CBF4 @ =0x08F6DC44
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
	movs r0, #0xA0
	lsls r0, r0, #0x02
	ldr r1, _0804CBF8 @ =0x08B59E52
	bl func_080028F8
	str r0, [r5, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x08
	ldr r1, _0804CBFC @ =0x09EE17AC
	ldr r2, _0804CC00 @ =0x09EE1798
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x20]
	ldr r0, [r6, #0x04]
	str r0, [r5, #0x24]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x28]
	ldrh r0, [r6, #0x14]
	adds r6, r5, #0x0
	adds r6, #0x4E
	movs r7, #0x00
	strh r0, [r6, #0x00]
	strh r7, [r5, #0x3C]
	adds r0, r5, #0x0
	adds r0, #0x4A
	strh r7, [r0, #0x00]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0804CC04 @ =0x00000201
	adds r1, r4, #0x0
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r0, r1
	str r0, [r5, #0x50]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r4, #0x80
	lsls r4, r4, #0x01
	adds r0, r0, r4
	negs r0, r0
	str r0, [r5, #0x30]
	ldrh r0, [r6, #0x00]
	cmp r0, #0x01
	beq _0804CC7C
	cmp r0, #0x01
	bgt _0804CC08
	cmp r0, #0x00
	beq _0804CC0E
	b _0804CC7C
	.byte 0x00, 0x00
_0804CBF4: .4byte 0x08F6DC44
_0804CBF8: .4byte 0x08B59E52
_0804CBFC: .4byte 0x09EE17AC
_0804CC00: .4byte 0x09EE1798
_0804CC04: .4byte 0x00000201
_0804CC08:
	cmp r0, #0x02
	beq _0804CC4C
	b _0804CC7C
_0804CC0E:
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x24]
	ldr r2, _0804CC48 @ =0x02039B84
	ldr r3, [r2, #0x00]
	movs r4, #0x98
	lsls r4, r4, #0x01
	adds r2, r3, r4
	ldr r2, [r2, #0x00]
	adds r4, #0x04
	adds r3, r3, r4
	ldr r3, [r3, #0x00]
	bl func_0801CB6C
	adds r1, r5, #0x0
	adds r1, #0x34
	strb r0, [r1, #0x00]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl func_0811D7CC
	adds r0, #0x01
	adds r1, r5, #0x0
	adds r1, #0x4C
	strh r0, [r1, #0x00]
	str r7, [r5, #0x38]
	b _0804CCA0
_0804CC48: .4byte 0x02039B84
_0804CC4C:
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x24]
	ldr r2, _0804CC78 @ =0x02039B84
	ldr r3, [r2, #0x00]
	movs r4, #0x98
	lsls r4, r4, #0x01
	adds r2, r3, r4
	ldr r2, [r2, #0x00]
	adds r4, #0x04
	adds r3, r3, r4
	ldr r3, [r3, #0x00]
	bl func_0801CB6C
	adds r1, r5, #0x0
	adds r1, #0x34
	strb r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x4C
	strh r7, [r0, #0x00]
	movs r0, #0x01
	str r0, [r5, #0x38]
	b _0804CCA0
_0804CC78: .4byte 0x02039B84
_0804CC7C:
	bl func_080065A4
	adds r1, r5, #0x0
	adds r1, #0x34
	movs r4, #0x00
	strb r0, [r1, #0x00]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x05
	bl func_0811D7CC
	adds r0, #0x04
	adds r1, r5, #0x0
	adds r1, #0x4C
	strh r0, [r1, #0x00]
	str r4, [r5, #0x38]
_0804CCA0:
	ldr r0, _0804CCC4 @ =0x08B22CE4
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r5, #0x40]
	ldr r0, _0804CCC8 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x44]
	adds r1, r5, #0x0
	adds r1, #0x48
	movs r0, #0x01
	strb r0, [r1, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0804CCC4: .4byte 0x08B22CE4
_0804CCC8: .4byte 0x08F69BA4
.syntax divided
