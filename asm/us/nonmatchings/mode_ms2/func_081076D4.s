.syntax unified
	.align 2, 0
	.global func_081076D4
	.thumb
	.thumb_func
	.type func_081076D4, %function
func_081076D4: @ 081076D4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	bl func_0810718C
	adds r4, r0, #0x0
	ldr r5, _08107748 @ =0x02035E2E
	movs r1, #0x00
	ldsh r0, [r5, r1]
	bl func_08107220
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _08107700
	ldrh r0, [r4, #0x04]
	lsls r0, r0, #0x05
	ldr r1, _0810774C @ =0x09A3D23C
	adds r0, r0, r1
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x0C
	bl func_08005BE8
_08107700:
	ldr r0, _08107750 @ =0x02035E2C
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x01
	bne _08107790
	movs r6, #0x00
_0810770C:
	movs r0, #0x00
	bl func_08005130
	adds r2, r0, #0x0
	lsls r4, r6, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0x06
	adds r0, #0x40
	adds r2, r2, r0
	movs r0, #0x01
	str r0, [sp, #0x000]
	movs r0, #0x00
	ldr r1, _08107754 @ =0x09A067DC
	movs r3, #0x20
	bl func_08101588
	lsls r1, r4, #0x01
	ldr r0, _08107758 @ =0x0500000C
	adds r1, r1, r0
	ldr r0, _0810775C @ =0x09A3D2C8
	movs r2, #0x02
	bl func_08005BE8
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x09
	ble _0810770C
	b _081078DC
_08107748: .4byte 0x02035E2E
_0810774C: .4byte 0x09A3D23C
_08107750: .4byte 0x02035E2C
_08107754: .4byte 0x09A067DC
_08107758: .4byte 0x0500000C
_0810775C: .4byte 0x09A3D2C8
_08107760:
	movs r0, #0x00
	bl func_08005130
	adds r2, r0, #0x0
	adds r2, #0x40
	ldr r1, _08107784 @ =0x09A067FC
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	movs r3, #0x20
	bl func_08101588
	ldr r0, _08107788 @ =0x09A3D248
	ldr r1, _0810778C @ =0x0500000C
	movs r2, #0x02
	bl func_08005BE8
	b _081077E0
_08107784: .4byte 0x09A067FC
_08107788: .4byte 0x09A3D248
_0810778C: .4byte 0x0500000C
_08107790:
	ldrh r0, [r4, #0x04]
	cmp r0, #0x03
	bne _08107820
	movs r1, #0x00
	ldsh r0, [r5, r1]
	bl func_08107220
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _081077B0
	ldr r1, _0810780C @ =0x09A3551C
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x01
	bl func_0800510C
_081077B0:
	movs r6, #0x00
	adds r7, r4, #0x6
_081077B4:
	lsls r0, r6, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #0x01
	adds r0, r7, r0
	movs r2, #0x00
	ldsh r5, [r0, r2]
	cmp r5, #0x00
	beq _081077D4
	ldr r0, _08107810 @ =0x02035E2E
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_08107220
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bgt _08107760
_081077D4:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	ble _081077B4
_081077E0:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	ble _081078DC
	movs r0, #0x00
	bl func_08005130
	adds r2, r0, #0x0
	adds r2, #0x40
	ldr r1, _08107814 @ =0x09A067DC
	movs r0, #0x01
	str r0, [sp, #0x000]
	movs r0, #0x00
	movs r3, #0x20
	bl func_08101588
	ldr r0, _08107818 @ =0x09A3D2C8
	ldr r1, _0810781C @ =0x0500000C
	movs r2, #0x02
	bl func_08005BE8
	b _081078DC
_0810780C: .4byte 0x09A3551C
_08107810: .4byte 0x02035E2E
_08107814: .4byte 0x09A067DC
_08107818: .4byte 0x09A3D2C8
_0810781C: .4byte 0x0500000C
_08107820:
	movs r2, #0x00
	ldsh r0, [r5, r2]
	bl func_08107220
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _0810783A
	ldr r1, _0810788C @ =0x09A3501C
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x01
	bl func_0800510C
_0810783A:
	movs r6, #0x00
	adds r7, r4, #0x6
_0810783E:
	lsls r1, r6, #0x10
	asrs r4, r1, #0x10
	lsls r0, r4, #0x01
	adds r0, r7, r0
	movs r2, #0x00
	ldsh r5, [r0, r2]
	adds r6, r1, #0x0
	cmp r5, #0x00
	beq _081078A0
	ldr r0, _08107890 @ =0x02035E2E
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bl func_08107220
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _081078A0
	movs r0, #0x00
	bl func_08005130
	adds r2, r0, #0x0
	lsls r0, r4, #0x06
	adds r0, #0x40
	adds r2, r2, r0
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	ldr r1, _08107894 @ =0x09A067FC
	movs r3, #0x20
	bl func_08101588
	lsls r1, r4, #0x01
	ldr r2, _08107898 @ =0x0500000C
	adds r1, r1, r2
	ldr r0, _0810789C @ =0x09A3D248
	movs r2, #0x02
	bl func_08005BE8
	b _081078CE
_0810788C: .4byte 0x09A3501C
_08107890: .4byte 0x02035E2E
_08107894: .4byte 0x09A067FC
_08107898: .4byte 0x0500000C
_0810789C: .4byte 0x09A3D248
_081078A0:
	movs r0, #0x00
	bl func_08005130
	adds r2, r0, #0x0
	asrs r4, r6, #0x10
	lsls r0, r4, #0x06
	adds r0, #0x40
	adds r2, r2, r0
	movs r0, #0x01
	str r0, [sp, #0x000]
	movs r0, #0x00
	ldr r1, _081078E4 @ =0x09A067DC
	movs r3, #0x20
	bl func_08101588
	lsls r4, r4, #0x01
	ldr r0, _081078E8 @ =0x0500000C
	adds r4, r4, r0
	ldr r0, _081078EC @ =0x09A3D2C8
	adds r1, r4, #0x0
	movs r2, #0x02
	bl func_08005BE8
_081078CE:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r6, r1
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	ble _0810783E
_081078DC:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_081078E4: .4byte 0x09A067DC
_081078E8: .4byte 0x0500000C
_081078EC: .4byte 0x09A3D2C8
.syntax divided
