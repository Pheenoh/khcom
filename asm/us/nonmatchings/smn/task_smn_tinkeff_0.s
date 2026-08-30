.syntax unified
	.align 2, 0
	.global task_smn_tinkeff_0
	.thumb
	.thumb_func
	.type task_smn_tinkeff_0, %function
task_smn_tinkeff_0: @ 08042F84
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x09
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _08043020 @ =0xFFFFFC00
	adds r0, r0, r1
	ldr r1, [r5, #0x04]
	adds r1, r1, r0
	str r1, [r4, #0x20]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x09
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _08043020 @ =0xFFFFFC00
	adds r0, r0, r1
	ldr r1, [r5, #0x08]
	adds r1, r1, r0
	str r1, [r4, #0x24]
	ldr r0, [r5, #0x0C]
	str r0, [r4, #0x28]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xE8
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x4C
	str r0, [r4, #0x2C]
	ldr r0, _08043024 @ =0x088A5D7A
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _08043028 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	adds r4, #0x08
	ldr r1, _0804302C @ =0x09EDE7E4
	ldr r2, _08043030 @ =0x09EDE7B4
	adds r0, r4, #0x0
	bl func_08005968
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	beq _08043040
	cmp r0, #0x01
	bgt _08043034
	cmp r0, #0x00
	beq _0804303A
	b _08043056
	.byte 0x00, 0x00
_08043020: .4byte 0xFFFFFC00
_08043024: .4byte 0x088A5D7A
_08043028: .4byte 0x08F69BA4
_0804302C: .4byte 0x09EDE7E4
_08043030: .4byte 0x09EDE7B4
_08043034:
	cmp r0, #0x02
	beq _0804304C
	b _08043056
_0804303A:
	adds r0, r4, #0x0
	movs r1, #0x00
	b _08043044
_08043040:
	adds r0, r4, #0x0
	movs r1, #0x01
_08043044:
	movs r2, #0x01
	bl func_080059A4
	b _08043056
_0804304C:
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl func_080059A4
_08043056:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
