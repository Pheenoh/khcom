.syntax unified
	.align 2, 0
	.global func_080E6804
	.thumb
	.thumb_func
	.type func_080E6804, %function
func_080E6804: @ 080E6804
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r12, r1
	movs r6, #0x00
	movs r5, #0x00
	ldr r0, _080E6888 @ =0x02034F78
	ldrb r1, [r0, #0x00]
	cmp r5, r1
	bge _080E6898
	ldr r0, _080E688C @ =0x0203C7B8
	ldr r0, [r0, #0x00]
	adds r7, r1, #0x0
	adds r3, r0, #0x4
_080E682A:
	ldr r0, [r3, #0x00]
	asrs r0, r0, #0x08
	cmp r0, #0x00
	bge _080E6834
	adds r0, #0x1F
_080E6834:
	lsls r0, r0, #0x0B
	lsrs r2, r0, #0x10
	ldr r0, [r3, #0x04]
	ldr r1, [r3, #0x08]
	adds r0, r0, r1
	asrs r0, r0, #0x08
	cmp r0, #0x00
	bge _080E6846
	adds r0, #0x0F
_080E6846:
	lsls r0, r0, #0x0C
	lsrs r4, r0, #0x10
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r0, r1, #0x0
	subs r0, #0x09
	cmp r2, r0
	ble _080E6890
	adds r0, #0x12
	cmp r2, r0
	bge _080E6890
	lsls r0, r4, #0x10
	asrs r2, r0, #0x10
	mov r1, r12
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r0, r1, #0x0
	subs r0, #0x0B
	cmp r2, r0
	ble _080E6890
	adds r0, #0x16
	cmp r2, r0
	bge _080E6890
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x02
	bls _080E6890
	movs r0, #0x00
	b _080E689A
_080E6888: .4byte 0x02034F78
_080E688C: .4byte 0x0203C7B8
_080E6890:
	adds r3, #0x18
	adds r5, #0x01
	cmp r5, r7
	blt _080E682A
_080E6898:
	movs r0, #0x01
_080E689A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
