.syntax unified
	.align 2, 0
	.global task_wlogo_nvl_1
	.thumb
	.thumb_func
	.type task_wlogo_nvl_1, %function
task_wlogo_nvl_1: @ 080B54D8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldrb r1, [r5, #0x00]
	cmp r1, #0x01
	beq _080B550E
	cmp r1, #0x01
	bgt _080B54EC
	cmp r1, #0x00
	beq _080B54F6
	b _080B55C2
_080B54EC:
	cmp r1, #0x02
	beq _080B554A
	cmp r1, #0x03
	beq _080B557C
	b _080B55C2
_080B54F6:
	ldrh r0, [r5, #0x02]
	adds r0, #0x01
	strh r0, [r5, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1D
	bls _080B55C2
	strh r1, [r5, #0x02]
	ldrb r0, [r5, #0x00]
	adds r0, #0x01
	strb r0, [r5, #0x00]
	b _080B55C2
_080B550E:
	ldrh r0, [r5, #0x02]
	adds r0, #0x01
	strh r0, [r5, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bls _080B55C2
	movs r0, #0x00
	strh r0, [r5, #0x02]
	ldrb r0, [r5, #0x0A]
	adds r0, #0x01
	strb r0, [r5, #0x0A]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x0F
	bls _080B5538
	movs r0, #0x10
	strb r0, [r5, #0x0A]
	ldrb r0, [r5, #0x00]
	adds r0, #0x01
	strb r0, [r5, #0x00]
_080B5538:
	ldrb r2, [r5, #0x0A]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl func_080057A0
	b _080B55C2
_080B554A:
	ldrh r0, [r5, #0x02]
	adds r0, #0x01
	strh r0, [r5, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x71
	bls _080B5562
	movs r0, #0x00
	strh r0, [r5, #0x02]
	ldrb r0, [r5, #0x00]
	adds r0, #0x01
	strb r0, [r5, #0x00]
_080B5562:
	ldrh r0, [r5, #0x02]
	cmp r0, #0x01
	bne _080B55C2
	ldr r0, _080B5574 @ =0x02034C50
	ldr r1, _080B5578 @ =0x09EF18A4
	movs r2, #0x00
	bl func_08000E14
	b _080B55C2
_080B5574: .4byte 0x02034C50
_080B5578: .4byte 0x09EF18A4
_080B557C:
	ldrh r0, [r5, #0x02]
	adds r0, #0x01
	strh r0, [r5, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bls _080B55C2
	movs r0, #0x00
	strh r0, [r5, #0x02]
	ldrb r0, [r5, #0x0A]
	subs r0, #0x01
	strb r0, [r5, #0x0A]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080B55B2
	movs r0, #0x00
	strb r0, [r5, #0x0A]
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl func_080057A0
	movs r0, #0x00
	bl func_0800501C
	movs r0, #0x00
	b _080B5678
_080B55B2:
	ldrb r2, [r5, #0x0A]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl func_080057A0
_080B55C2:
	ldrh r1, [r5, #0x08]
	adds r0, r1, #0x0
	subs r0, #0x32
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4A
	bhi _080B5618
	ldrh r0, [r5, #0x06]
	adds r0, #0x01
	strh r0, [r5, #0x06]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x0E
	bls _080B5662
	movs r0, #0x00
	strh r0, [r5, #0x06]
	ldrb r0, [r5, #0x04]
	adds r0, #0x01
	strb r0, [r5, #0x04]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x04
	ble _080B55F4
	movs r0, #0x05
	strb r0, [r5, #0x04]
_080B55F4:
	movs r4, #0x04
	ldsb r4, [r5, r4]
	lsls r4, r4, #0x0A
	ldr r0, _080B5614 @ =0x09638C84
	adds r4, r4, r0
	movs r0, #0x00
	bl func_08005130
	adds r1, r0, #0x0
	movs r2, #0xD0
	lsls r2, r2, #0x02
	adds r0, r4, #0x0
	bl func_080043B4
	b _080B5662
	.byte 0x00, 0x00
_080B5614: .4byte 0x09638C84
_080B5618:
	adds r0, r1, #0x0
	subs r0, #0x87
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4A
	bhi _080B5662
	ldrh r0, [r5, #0x06]
	adds r0, #0x01
	strh r0, [r5, #0x06]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x0E
	bls _080B5662
	movs r0, #0x00
	strh r0, [r5, #0x06]
	ldrb r0, [r5, #0x04]
	subs r0, #0x01
	strb r0, [r5, #0x04]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bgt _080B5646
	movs r0, #0x00
	strb r0, [r5, #0x04]
_080B5646:
	movs r4, #0x04
	ldsb r4, [r5, r4]
	lsls r4, r4, #0x0A
	ldr r0, _080B5680 @ =0x09638C84
	adds r4, r4, r0
	movs r0, #0x00
	bl func_08005130
	adds r1, r0, #0x0
	movs r2, #0xD0
	lsls r2, r2, #0x02
	adds r0, r4, #0x0
	bl func_080043B4
_080B5662:
	ldrh r0, [r5, #0x08]
	adds r0, #0x01
	strh r0, [r5, #0x08]
	ldr r4, _080B5684 @ =0x02034C50
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
	movs r0, #0x01
_080B5678:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080B5680: .4byte 0x09638C84
_080B5684: .4byte 0x02034C50
.syntax divided
