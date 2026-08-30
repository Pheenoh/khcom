.syntax unified
	.align 2, 0
	.global task_fld_sora_1
	.thumb
	.thumb_func
	.type task_fld_sora_1, %function
task_fld_sora_1: @ 08033BC8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x064
	adds r7, r0, #0x0
	mov r10, r1
	ldr r0, _08033C18 @ =0x02039BA0
	mov r8, r0
	ldr r1, [r0, #0x00]
	mov r9, r1
	mov r6, r9
	adds r6, #0x18
	adds r4, r7, #0x0
	adds r4, #0xA4
	ldrh r1, [r4, #0x00]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r2, r8
	cmp r5, #0x00
	beq _08033CA8
	ldr r0, _08033C1C @ =0x0000FFF7
	ands r0, r1
	strh r0, [r4, #0x00]
	adds r1, r7, #0x0
	adds r1, #0x94
	ldr r0, [r1, #0x00]
	subs r0, #0x02
	mov r9, r1
	cmp r0, #0x0A
	bhi _08033CA0
	lsls r0, r0, #0x02
	ldr r1, _08033C20 @ =0x08033C24
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_08033C18: .4byte 0x02039BA0
_08033C1C: .4byte 0x0000FFF7
_08033C20: .4byte 0x08033C24
	.byte 0x56, 0x3C, 0x03, 0x08, 0x56, 0x3C, 0x03, 0x08, 0x56, 0x3C, 0x03, 0x08, 0x62, 0x3C, 0x03, 0x08
	.byte 0x6C, 0x3C, 0x03, 0x08, 0x6C, 0x3C, 0x03, 0x08, 0x90, 0x3C, 0x03, 0x08, 0x90, 0x3C, 0x03, 0x08
	.byte 0x90, 0x3C, 0x03, 0x08, 0xA0, 0x3C, 0x03, 0x08, 0x50, 0x3C, 0x03, 0x08, 0x03, 0x20, 0x4B, 0x46
	.byte 0x18, 0x60, 0x10, 0x68, 0x01, 0x6F, 0x80, 0x22, 0x12, 0x04, 0x11, 0x43, 0x01, 0x67, 0x01, 0x49
	.byte 0x15, 0xE0, 0x00, 0x00, 0xDD, 0x24, 0x03, 0x08, 0x06, 0x49, 0x50, 0x46, 0xCD, 0xF7, 0x8C, 0xF9
	.byte 0x05, 0x48, 0x01, 0x68, 0x00, 0x20, 0x88, 0x66, 0x39, 0x1C, 0x98, 0x31, 0x01, 0x20, 0x08, 0x80
	.byte 0x8E, 0xE2, 0x00, 0x00, 0x3D, 0x2C, 0x03, 0x08, 0xA0, 0x9B, 0x03, 0x02, 0x02, 0x49, 0x50, 0x46
	.byte 0xCD, 0xF7, 0x7A, 0xF9, 0x80, 0xE2, 0x00, 0x00, 0x51, 0x31, 0x03, 0x08
_08033CA0:
	movs r0, #0x00
	mov r4, r9
	str r0, [r4, #0x00]
	b _080341A4
_08033CA8:
	bl func_080DFC24
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x00
	beq _08033CF0
	adds r0, r7, #0x0
	adds r0, #0x98
	strh r5, [r0, #0x00]
	ldr r1, _08033CEC @ =0x08033335
	mov r0, r10
	bl func_08000F8C
	adds r0, r7, #0x0
	adds r0, #0x24
	bl func_08000EA4
	adds r1, r7, #0x0
	adds r1, #0x94
	movs r0, #0x0F
	str r0, [r1, #0x00]
	bl func_080DFC24
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _08033CE0
	b _080341D0
_08033CE0:
	ldrh r0, [r4, #0x00]
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r4, #0x00]
	b _080341D0
	.byte 0x00, 0x00
_08033CEC: .4byte 0x08033335
_08033CF0:
	mov r5, r8
	ldr r0, [r5, #0x00]
	ldr r2, [r0, #0x70]
	movs r4, #0x80
	lsls r4, r4, #0x0B
	ands r4, r2
	cmp r4, #0x00
	beq _08033D14
	adds r0, r7, #0x0
	adds r0, #0x98
	strh r1, [r0, #0x00]
	ldr r1, _08033D10 @ =0x08032269
	mov r0, r10
	bl func_08000F8C
	b _080341C8
_08033D10: .4byte 0x08032269
_08033D14:
	mov r0, r9
	ldr r0, [r0, #0x18]
	str r0, [sp, #0x040]
	ldr r1, [r6, #0x04]
	str r1, [sp, #0x044]
	adds r0, r7, #0x0
	adds r0, #0x94
	ldr r1, [r0, #0x00]
	mov r9, r0
	cmp r1, #0x01
	bls _08033D2C
	b _08033E6C
_08033D2C:
	movs r4, #0x80
	lsls r4, r4, #0x07
	ands r2, r4
	cmp r2, #0x00
	bne _08033DA0
	adds r0, r6, #0x0
	bl func_08031F60
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x70]
	ands r0, r4
	cmp r0, #0x00
	bne _08033DA0
	bl func_08001384
	movs r1, #0xF0
	ands r1, r0
	cmp r1, #0x00
	beq _08033DA0
	ldr r0, [r6, #0x10]
	adds r0, #0x80
	str r0, [r6, #0x10]
	adds r0, r7, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl func_08031F98
	ldr r0, [r6, #0x10]
	ldr r1, _08033D80 @ =0x00000266
	cmp r0, r1
	ble _08033D6E
	str r1, [r6, #0x10]
_08033D6E:
	ldrh r0, [r7, #0x12]
	cmp r0, #0x00
	bne _08033DB8
	ldrh r0, [r7, #0x16]
	cmp r0, #0x03
	beq _08033D84
	cmp r0, #0x07
	beq _08033D92
	b _08033DB8
_08033D80: .4byte 0x00000266
_08033D84:
	adds r0, r7, #0x0
	adds r0, #0xAC
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x00]
	bl func_0811FE70
	b _08033DB8
_08033D92:
	adds r0, r7, #0x0
	adds r0, #0xAC
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x02]
	bl func_0811FE70
	b _08033DB8
_08033DA0:
	adds r0, r7, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_08031F98
	ldr r0, [r6, #0x10]
	subs r0, #0x80
	str r0, [r6, #0x10]
	cmp r0, #0x00
	bge _08033DB8
	movs r0, #0x00
	str r0, [r6, #0x10]
_08033DB8:
	ldr r3, _08033E30 @ =0x08121400
	ldrb r0, [r6, #0x14]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r4, #0x00
	ldsh r0, [r0, r4]
	ldr r2, [r6, #0x10]
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r6, #0x00]
	adds r0, r0, r1
	str r0, [r6, #0x00]
	ldrb r0, [r6, #0x14]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r0, [r0, r5]
	negs r0, r0
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r6, #0x04]
	adds r0, r0, r1
	str r0, [r6, #0x04]
	bl func_08001390
	movs r5, #0x02
	adds r1, r5, #0x0
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r4, #0x00
	beq _08033E3C
	ldr r0, _08033E34 @ =0x02039BA0
	ldr r2, [r0, #0x00]
	movs r3, #0x00
	str r3, [r2, #0x68]
	ldr r0, [r2, #0x70]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r2, #0x70]
	adds r0, r7, #0x0
	adds r0, #0x98
	strh r3, [r0, #0x00]
	mov r0, r9
	str r5, [r0, #0x00]
	ldr r1, _08033E38 @ =0x080324DD
	mov r0, r10
	bl func_08000F8C
	adds r0, r7, #0x0
	adds r0, #0xAC
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x04]
	bl func_0811FE70
	b _08033E7E
_08033E30: .4byte 0x08121400
_08033E34: .4byte 0x02039BA0
_08033E38: .4byte 0x080324DD
_08033E3C:
	bl func_08001390
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _08033E7E
	adds r0, r7, #0x0
	adds r0, #0x98
	strh r4, [r0, #0x00]
	ldr r0, _08033E64 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x68]
	movs r0, #0x0B
	mov r1, r9
	str r0, [r1, #0x00]
	ldr r1, _08033E68 @ =0x0803366D
	mov r0, r10
	bl func_08000F8C
	b _08033E7E
_08033E64: .4byte 0x02039BA0
_08033E68: .4byte 0x0803366D
_08033E6C:
	adds r0, r7, #0x0
	adds r0, #0x08
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08033E7E
	mov r2, r9
	str r4, [r2, #0x00]
_08033E7E:
	adds r0, r7, #0x0
	adds r0, #0x64
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08033EC4
	ldr r0, [r7, #0x6C]
	cmp r0, #0x05
	beq _08033EC4
	cmp r0, #0x05
	bhi _08033E98
	cmp r0, #0x03
	beq _08033EC4
	b _08033E9C
_08033E98:
	cmp r0, #0x0B
	beq _08033EC4
_08033E9C:
	adds r0, r7, #0x0
	adds r0, #0x66
	ldrh r1, [r0, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08033EC4
	ldr r1, [r6, #0x10]
	movs r0, #0xE6
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r6, #0x10]
	ldr r0, [r6, #0x00]
	ldr r1, [r7, #0x70]
	adds r0, r0, r1
	str r0, [r6, #0x00]
	ldr r0, [r6, #0x04]
	ldr r1, [r7, #0x74]
	adds r0, r0, r1
	str r0, [r6, #0x04]
_08033EC4:
	adds r0, r6, #0x0
	bl func_08031D74
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08033ED2
	b _0803413E
_08033ED2:
	ldr r3, [sp, #0x040]
	str r3, [r6, #0x00]
	ldr r4, [sp, #0x044]
	str r4, [r6, #0x04]
	adds r0, r6, #0x0
	adds r1, r7, #0x0
	bl func_08031E48
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x00
	beq _08033F30
	cmp r0, #0x01
	beq _08033F06
	cmp r0, #0x02
	beq _08033EF4
	b _0803413E
_08033EF4:
	adds r0, r7, #0x0
	adds r0, #0x98
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r0, #0x06
	mov r5, r9
	str r0, [r5, #0x00]
	movs r0, #0xD3
	b _08033F16
_08033F06:
	adds r0, r7, #0x0
	adds r0, #0x98
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r0, #0x06
	mov r2, r9
	str r0, [r2, #0x00]
	movs r0, #0x2D
_08033F16:
	strb r0, [r6, #0x14]
	ldr r0, _08033F28 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	str r1, [r0, #0x68]
	ldr r1, _08033F2C @ =0x08032C3D
	mov r0, r10
	bl func_08000F8C
	b _0803413E
_08033F28: .4byte 0x02039BA0
_08033F2C: .4byte 0x08032C3D
_08033F30:
	adds r0, r6, #0x0
	bl func_08031EC4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08033F60
	ldr r0, [r7, #0x04]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, _08033F5C @ =0x02039BA0
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x70]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2, #0x70]
	b _080341D0
	.byte 0x00, 0x00
_08033F5C: .4byte 0x02039BA0
_08033F60:
	ldrb r0, [r6, #0x14]
	cmp r0, #0x53
	beq _08033FAC
	cmp r0, #0x53
	bgt _08033F7E
	cmp r0, #0x2D
	beq _08033FD4
	cmp r0, #0x2D
	bgt _08033F78
	cmp r0, #0x00
	beq _08034000
	b _0803404C
_08033F78:
	cmp r0, #0x40
	beq _08034018
	b _0803404C
_08033F7E:
	cmp r0, #0xAD
	beq _08033F96
	cmp r0, #0xAD
	bgt _08033F8C
	cmp r0, #0x80
	beq _08033FE8
	b _0803404C
_08033F8C:
	cmp r0, #0xC0
	beq _08034030
	cmp r0, #0xD3
	beq _08033FBE
	b _0803404C
_08033F96:
	ldr r2, _08033FA8 @ =0xFFFFFF00
	movs r3, #0x00
	str r3, [sp, #0x048]
	mov r8, r3
	movs r4, #0xC0
	lsls r4, r4, #0x01
	str r4, [sp, #0x060]
	b _08034058
	.byte 0x00, 0x00
_08033FA8: .4byte 0xFFFFFF00
_08033FAC:
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r5, #0x00
	str r5, [sp, #0x048]
	mov r8, r5
	movs r0, #0xC0
	lsls r0, r0, #0x01
	str r0, [sp, #0x060]
	b _08034058
_08033FBE:
	ldr r2, _08033FCC @ =0xFFFFFF00
	movs r1, #0x00
	str r1, [sp, #0x048]
	mov r8, r1
	ldr r3, _08033FD0 @ =0xFFFFFE80
	str r3, [sp, #0x060]
	b _08034058
_08033FCC: .4byte 0xFFFFFF00
_08033FD0: .4byte 0xFFFFFE80
_08033FD4:
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r4, #0x00
	str r4, [sp, #0x048]
	mov r8, r4
	ldr r5, _08033FE4 @ =0xFFFFFE80
	str r5, [sp, #0x060]
	b _08034058
_08033FE4: .4byte 0xFFFFFE80
_08033FE8:
	ldr r2, _08033FFC @ =0xFFFFFE00
	movs r0, #0xC0
	str r0, [sp, #0x048]
	movs r1, #0x80
	lsls r1, r1, #0x02
	mov r8, r1
	movs r3, #0xC0
	str r3, [sp, #0x060]
	b _08034058
	.byte 0x00, 0x00
_08033FFC: .4byte 0xFFFFFE00
_08034000:
	ldr r2, _08034014 @ =0xFFFFFE00
	movs r4, #0xC0
	negs r4, r4
	str r4, [sp, #0x048]
	movs r5, #0x80
	lsls r5, r5, #0x02
	mov r8, r5
	str r4, [sp, #0x060]
	b _08034058
	.byte 0x00, 0x00
_08034014: .4byte 0xFFFFFE00
_08034018:
	movs r2, #0xC0
	lsls r2, r2, #0x01
	ldr r0, _08034028 @ =0xFFFFFECD
	str r0, [sp, #0x048]
	mov r8, r2
	ldr r1, _0803402C @ =0x00000133
	str r1, [sp, #0x060]
	b _08034058
_08034028: .4byte 0xFFFFFECD
_0803402C: .4byte 0x00000133
_08034030:
	ldr r2, _08034040 @ =0xFFFFFE80
	ldr r3, _08034044 @ =0xFFFFFECD
	str r3, [sp, #0x048]
	mov r8, r2
	ldr r4, _08034048 @ =0x00000133
	str r4, [sp, #0x060]
	b _08034058
	.byte 0x00, 0x00
_08034040: .4byte 0xFFFFFE80
_08034044: .4byte 0xFFFFFECD
_08034048: .4byte 0x00000133
_0803404C:
	movs r5, #0x00
	str r5, [sp, #0x060]
	mov r8, r5
	movs r0, #0x00
	str r0, [sp, #0x048]
	movs r2, #0x00
_08034058:
	mov r1, sp
	adds r1, #0x10
	str r1, [sp, #0x054]
	mov r12, r1
	str r6, [sp, #0x05C]
	mov r3, r12
	adds r4, r6, #0x0
	ldm r4!, {r0, r1, r5}
	stm r3!, {r0, r1, r5}
	ldr r0, [r4, #0x00]
	str r0, [r3, #0x00]
	mov r12, sp
	ldr r3, [sp, #0x054]
	str r3, [sp, #0x05C]
	mov r4, r12
	adds r5, r3, #0x0
	ldm r5!, {r0, r1, r3}
	stm r4!, {r0, r1, r3}
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x00]
	ldr r0, [sp, #0x000]
	adds r0, r0, r2
	str r0, [sp, #0x000]
	ldr r0, [sp, #0x004]
	ldr r4, [sp, #0x048]
	adds r0, r0, r4
	str r0, [sp, #0x004]
	ldr r0, [sp, #0x010]
	add r0, r8
	str r0, [sp, #0x010]
	ldr r5, [sp, #0x054]
	ldr r0, [r5, #0x04]
	ldr r1, [sp, #0x060]
	adds r0, r0, r1
	str r0, [r5, #0x04]
	mov r0, sp
	str r2, [sp, #0x04C]
	bl func_08031D74
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, [sp, #0x054]
	bl func_08031D74
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, [sp, #0x04C]
	cmp r4, #0x00
	beq _080340FA
	cmp r0, #0x00
	bne _0803413A
	mov r2, sp
	adds r2, #0x20
	str r2, [sp, #0x058]
	adds r1, r2, #0x0
	adds r0, r6, #0x0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x020]
	add r0, r8
	str r0, [sp, #0x020]
	ldr r0, [r2, #0x04]
	ldr r1, [sp, #0x060]
	adds r0, r0, r1
	str r0, [r2, #0x04]
	ldr r0, [sp, #0x058]
	bl func_08031DF8
	ldr r2, [sp, #0x058]
	str r0, [r2, #0x0C]
	ldr r1, [r2, #0x08]
	cmp r0, r1
	blt _0803413A
	adds r0, r6, #0x0
	ldr r1, [sp, #0x058]
	ldm r1!, {r3, r4, r5}
	stm r0!, {r3, r4, r5}
	b _08034136
_080340FA:
	cmp r0, #0x00
	beq _0803413A
	add r0, sp, #0x030
	mov r8, r0
	mov r1, r8
	adds r0, r6, #0x0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x030]
	adds r0, r0, r2
	str r0, [sp, #0x030]
	mov r1, r8
	ldr r0, [r1, #0x04]
	ldr r2, [sp, #0x048]
	adds r0, r0, r2
	str r0, [r1, #0x04]
	mov r0, r8
	bl func_08031DF8
	mov r3, r8
	str r0, [r3, #0x0C]
	ldr r1, [r3, #0x08]
	cmp r0, r1
	blt _0803413A
	adds r0, r6, #0x0
	mov r1, r8
	ldm r1!, {r2, r4, r5}
	stm r0!, {r2, r4, r5}
_08034136:
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
_0803413A:
	movs r0, #0x00
	str r0, [r6, #0x10]
_0803413E:
	adds r0, r7, #0x0
	bl func_08031F1C
	adds r2, r0, #0x0
	ldr r1, [r6, #0x0C]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	bne _08034156
	ldr r0, [r6, #0x08]
	str r0, [r6, #0x0C]
	b _080341A4
_08034156:
	ldr r0, [r6, #0x08]
	cmp r2, r0
	beq _08034198
	ldr r0, [r6, #0x10]
	asrs r0, r0, #0x02
	str r0, [r6, #0x10]
	adds r0, r7, #0x0
	adds r0, #0xA0
	movs r1, #0x00
	str r1, [r0, #0x00]
	subs r0, #0x08
	strh r1, [r0, #0x00]
	ldr r0, _08034190 @ =0x02039BA0
	ldr r2, [r0, #0x00]
	str r1, [r2, #0x68]
	ldr r0, [r2, #0x70]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r2, #0x70]
	movs r0, #0x04
	mov r3, r9
	str r0, [r3, #0x00]
	ldr r1, _08034194 @ =0x080324DD
	mov r0, r10
	bl func_08000F8C
	b _080341A4
	.byte 0x00, 0x00
_08034190: .4byte 0x02039BA0
_08034194: .4byte 0x080324DD
_08034198:
	cmp r2, r1
	beq _080341A4
	ldr r0, _080341E4 @ =0x02039BA0
	ldr r1, [r0, #0x00]
	movs r0, #0x00
	str r0, [r1, #0x68]
_080341A4:
	adds r0, r7, #0x0
	adds r0, #0x38
	ldr r1, [r6, #0x00]
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	bl func_08012324
	ldr r0, [r6, #0x00]
	ldr r1, [r6, #0x04]
	ldr r2, [r6, #0x08]
	adds r1, r1, r2
	bl func_080E0298
	adds r0, r7, #0x0
	adds r0, #0x08
	bl func_08005A64
	str r0, [r7, #0x20]
_080341C8:
	adds r0, r7, #0x0
	adds r0, #0x24
	bl func_08000EA4
_080341D0:
	movs r0, #0x01
	add sp, #0x064
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080341E4: .4byte 0x02039BA0
.syntax divided
