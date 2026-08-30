.syntax unified
	.align 2, 0
	.global task_bos_lst_lsr_1
	.thumb
	.thumb_func
	.type task_bos_lst_lsr_1, %function
task_bos_lst_lsr_1: @ 08111728
	push {r4, r5, r6, lr}
	add sp, #-0x00C
	adds r5, r0, #0x0
	movs r0, #0x00
	ldsh r6, [r5, r0]
	cmp r6, #0x01
	beq _0811174A
	adds r4, r5, #0x0
	adds r4, #0x44
	cmp r6, #0x01
	bgt _08111740
	b _0811185E
_08111740:
	cmp r6, #0x02
	beq _08111764
	cmp r6, #0x03
	beq _08111794
	b _0811185E
_0811174A:
	ldrh r0, [r5, #0x12]
	subs r0, #0x01
	strh r0, [r5, #0x12]
	lsls r0, r0, #0x10
	adds r4, r5, #0x0
	adds r4, #0x44
	cmp r0, #0x00
	ble _0811175C
	b _0811185E
_0811175C:
	movs r0, #0x02
	strh r0, [r5, #0x00]
	movs r0, #0x00
	strh r0, [r5, #0x12]
_08111764:
	ldrh r0, [r5, #0x10]
	adds r0, #0x01
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x14
	ldsh r1, [r5, r2]
	adds r4, r5, #0x0
	adds r4, #0x44
	cmp r0, r1
	blt _0811185E
	movs r0, #0x03
	strh r0, [r5, #0x00]
	movs r0, #0x00
	strh r0, [r5, #0x10]
	adds r0, r4, #0x0
	bl func_08005B64
	adds r0, r4, #0x0
	movs r1, #0x06
	movs r2, #0x01
	bl func_08005A00
	b _0811185E
_08111794:
	movs r1, #0x10
	ldsh r0, [r5, r1]
	cmp r0, #0x0F
	ble _081117AE
	movs r0, #0x00
	strh r0, [r5, #0x00]
	strh r0, [r5, #0x10]
	adds r0, r4, #0x0
	movs r1, #0x04
	movs r2, #0x00
	bl func_08005A00
	b _0811185E
_081117AE:
	ldr r0, _081117F0 @ =0x0000010D
	ldr r1, [r5, #0x30]
	ldr r2, [r5, #0x34]
	ldr r3, [r5, #0x38]
	movs r4, #0x08
	str r4, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	bl func_08011F78
	ldrh r0, [r5, #0x10]
	ands r6, r0
	cmp r6, #0x00
	bne _081117D0
	adds r0, r5, #0x0
	bl func_08111678
_081117D0:
	ldr r0, _081117F4 @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r1, [r1, #0x7C]
	ldr r3, [r5, #0x30]
	ldr r2, [r1, #0x04]
	subs r1, r3, r2
	adds r4, r0, #0x0
	cmp r1, #0x00
	bge _081117E4
	negs r1, r1
_081117E4:
	ldr r0, _081117F8 @ =0x0000017F
	cmp r1, r0
	bgt _081117FC
	str r2, [r5, #0x30]
	b _08111818
	.byte 0x00, 0x00
_081117F0: .4byte 0x0000010D
_081117F4: .4byte 0x02039B84
_081117F8: .4byte 0x0000017F
_081117FC:
	cmp r3, r2
	ble _0811180C
	ldr r2, _08111808 @ =0xFFFFFE80
	adds r0, r3, r2
	b _08111816
	.byte 0x00, 0x00
_08111808: .4byte 0xFFFFFE80
_0811180C:
	cmp r3, r2
	bge _08111818
	movs r1, #0xC0
	lsls r1, r1, #0x01
	adds r0, r3, r1
_08111816:
	str r0, [r5, #0x30]
_08111818:
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r3, [r5, #0x34]
	ldr r2, [r0, #0x08]
	subs r1, r3, r2
	cmp r1, #0x00
	bge _08111828
	negs r1, r1
_08111828:
	ldr r0, _08111834 @ =0x0000017F
	cmp r1, r0
	bgt _08111838
	str r2, [r5, #0x34]
	b _08111854
	.byte 0x00, 0x00
_08111834: .4byte 0x0000017F
_08111838:
	cmp r3, r2
	ble _08111848
	ldr r2, _08111844 @ =0xFFFFFE80
	adds r0, r3, r2
	b _08111852
	.byte 0x00, 0x00
_08111844: .4byte 0xFFFFFE80
_08111848:
	cmp r3, r2
	bge _08111854
	movs r1, #0xC0
	lsls r1, r1, #0x01
	adds r0, r3, r1
_08111852:
	str r0, [r5, #0x34]
_08111854:
	ldrh r0, [r5, #0x10]
	adds r0, #0x01
	strh r0, [r5, #0x10]
	adds r4, r5, #0x0
	adds r4, #0x44
_0811185E:
	adds r0, r4, #0x0
	bl func_08005A64
	movs r0, #0x01
	add sp, #0x00C
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
