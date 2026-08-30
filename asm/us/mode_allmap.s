@ Generated with Luvdis v0.8.0
.syntax unified
.text
@ Begin embedded Luvdis macros
	.macro arm_func_start name
	.align 2, 0
	.global \name
	.arm
	.type \name, %function
	.endm

	.macro arm_func_end name
	.size \name, .-\name
	.endm

	.macro thumb_func_start name
	.align 2, 0
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro non_word_aligned_thumb_func_start name
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro thumb_func_end name
	.size \name, .-\name
	.endm
@ End embedded Luvdis macros

	thumb_func_start mode_allmap_0
mode_allmap_0: @ 080D31C4
	push {r4, r5, r6, lr}
	adds r1, r0, #0x0
	ldr r6, _080D3318 @ =0x02034E81
	movs r0, #0x00
	strb r0, [r6, #0x00]
	cmp r1, #0x01
	bne _080D31D4
	strb r1, [r6, #0x00]
_080D31D4:
	movs r0, #0x00
	movs r1, #0x0E
	bl func_08001F5C
	bl func_080D4D44
	bl func_08004DB0
	movs r0, #0x03
	movs r1, #0x01
	movs r2, #0x1C
	movs r3, #0x08
	bl func_08005074
	movs r0, #0x03
	movs r1, #0x03
	bl func_080055C8
	ldr r1, _080D331C @ =0x097B62B8
	movs r2, #0xF6
	lsls r2, r2, #0x04
	movs r0, #0x03
	bl func_080050B8
	ldr r1, _080D3320 @ =0x09849F78
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r0, #0x03
	bl func_080050DC
	ldr r1, _080D3324 @ =0x0983AD98
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x03
	bl func_0800510C
	movs r0, #0x02
	movs r1, #0x01
	movs r2, #0x1D
	movs r3, #0x08
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x00
	bl func_080055C8
	ldr r1, _080D3328 @ =0x08125E24
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x02
	bl func_0800510C
	bl func_080D30C8
	bl func_080D313C
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1A
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x02
	bl func_080055C8
	ldr r1, _080D332C @ =0x0976B340
	movs r2, #0x90
	lsls r2, r2, #0x06
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080D3330 @ =0x0984A0F8
	movs r0, #0x00
	movs r2, #0xE0
	bl func_080050DC
	bl func_080D2F64
	ldr r1, _080D3334 @ =0x0203C4C0
	movs r0, #0x00
	movs r2, #0x02
	movs r3, #0x04
	bl func_0800516C
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x1B
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x02
	bl func_080055C8
	ldr r1, _080D3338 @ =0x0203C510
	movs r0, #0x01
	movs r2, #0x02
	movs r3, #0x04
	bl func_0800516C
	ldr r4, _080D333C @ =0x0203C4F0
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _080D3340 @ =0x09EF4E08
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_08000E14
	ldr r0, _080D3344 @ =0x0203C4E0
	movs r5, #0x00
	str r5, [r0, #0x00]
	bl func_080D4EBC
	ldr r4, _080D3348 @ =0x04000208
	strh r5, [r4, #0x00]
	ldr r2, _080D334C @ =0x04000200
	ldrh r0, [r2, #0x00]
	movs r1, #0x04
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r2, _080D3350 @ =0x04000004
	ldrh r1, [r2, #0x00]
	movs r0, #0xFF
	ands r0, r1
	strh r0, [r2, #0x00]
	ldrh r0, [r2, #0x00]
	ldr r3, _080D3354 @ =0x00005020
	adds r1, r3, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _080D3358 @ =0x080D2F21
	bl func_08006C40
	movs r0, #0x01
	strh r0, [r4, #0x00]
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	ldrb r0, [r6, #0x00]
	cmp r0, #0x00
	beq _080D3300
	ldr r0, _080D335C @ =0x0203DB10
	movs r1, #0xFF
	movs r2, #0x80
	bl func_08120EF8
_080D3300:
	ldr r0, _080D3360 @ =0x0203C534
	movs r1, #0x1E
	strh r1, [r0, #0x00]
	ldr r0, _080D3364 @ =0x0203C508
	strh r1, [r0, #0x00]
	ldr r0, _080D3368 @ =0x02034E38
	strh r5, [r0, #0x00]
	ldr r0, _080D336C @ =0x02034E3A
	strh r5, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D3318: .4byte 0x02034E81
_080D331C: .4byte 0x097B62B8
_080D3320: .4byte 0x09849F78
_080D3324: .4byte 0x0983AD98
_080D3328: .4byte 0x08125E24
_080D332C: .4byte 0x0976B340
_080D3330: .4byte 0x0984A0F8
_080D3334: .4byte 0x0203C4C0
_080D3338: .4byte 0x0203C510
_080D333C: .4byte 0x0203C4F0
_080D3340: .4byte 0x09EF4E08
_080D3344: .4byte 0x0203C4E0
_080D3348: .4byte 0x04000208
_080D334C: .4byte 0x04000200
_080D3350: .4byte 0x04000004
_080D3354: .4byte 0x00005020
_080D3358: .4byte 0x080D2F21
_080D335C: .4byte 0x0203DB10
_080D3360: .4byte 0x0203C534
_080D3364: .4byte 0x0203C508
_080D3368: .4byte 0x02034E38
_080D336C: .4byte 0x02034E3A
	thumb_func_start func_080D3370
func_080D3370: @ 080D3370
	push {r4, r5, lr}
	movs r0, #0x0A
	movs r1, #0x01
	bl func_080062F4
	ldr r5, _080D3398 @ =0x05000140
	ldr r4, _080D339C @ =0x02034E40
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x10
	bl func_08117FE8
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0x20
	bl func_08005BE8
	pop {r4, r5}
	pop {r0}
	bx r0
_080D3398: .4byte 0x05000140
_080D339C: .4byte 0x02034E40
	thumb_func_start mode_allmap_1
mode_allmap_1: @ 080D33A0
	push {r4, lr}
	bl func_0801CC80
	ldr r4, _080D33E4 @ =0x0203C4F0
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
	ldr r4, _080D33E8 @ =0x0203C4E0
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	bne _080D3400
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3400
	ldr r0, _080D33EC @ =0x0203C534
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D33F8
	ldr r0, _080D33F0 @ =0x0203C508
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D33F8
	movs r0, #0x01
	str r0, [r4, #0x00]
	ldr r1, _080D33F4 @ =0x02034E3C
	movs r0, #0x10
	strh r0, [r1, #0x00]
	b _080D3400
	.byte 0x00, 0x00
_080D33E4: .4byte 0x0203C4F0
_080D33E8: .4byte 0x0203C4E0
_080D33EC: .4byte 0x0203C534
_080D33F0: .4byte 0x0203C508
_080D33F4: .4byte 0x02034E3C
_080D33F8:
	ldr r0, _080D3484 @ =0x02034E80
	ldrb r0, [r0, #0x00]
	bl func_080E052C
_080D3400:
	ldr r0, _080D3488 @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	bne _080D3462
	ldr r1, _080D348C @ =0x0203C534
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D3414
	subs r0, #0x01
	strh r0, [r1, #0x00]
_080D3414:
	ldr r1, _080D3490 @ =0x0203C508
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D3420
	subs r0, #0x01
	strh r0, [r1, #0x00]
_080D3420:
	ldr r4, _080D3494 @ =0x02034E3C
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	ble _080D344C
	cmp r0, #0x10
	bne _080D3432
	bl func_080D3008
_080D3432:
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	movs r1, #0x00
	ldsh r0, [r4, r1]
	bl func_080D3034
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bne _080D344C
	bl func_080D3370
_080D344C:
	ldr r0, _080D348C @ =0x0203C534
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D3462
	ldr r0, _080D3490 @ =0x0203C508
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D3462
	ldr r1, _080D3488 @ =0x0203C4E0
	movs r0, #0x03
	str r0, [r1, #0x00]
_080D3462:
	bl func_080D3050
	ldr r0, _080D3488 @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	subs r0, #0x02
	cmp r0, #0x01
	bhi _080D3498
	movs r0, #0x00
	bl func_08004FC8
	movs r0, #0x01
	bl func_08004FC8
	bl func_080D51D8
	b _080D34A4
	.byte 0x00, 0x00
_080D3484: .4byte 0x02034E80
_080D3488: .4byte 0x0203C4E0
_080D348C: .4byte 0x0203C534
_080D3490: .4byte 0x0203C508
_080D3494: .4byte 0x02034E3C
_080D3498:
	movs r0, #0x00
	bl func_0800501C
	movs r0, #0x01
	bl func_0800501C
_080D34A4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start mode_allmap_2
mode_allmap_2: @ 080D34AC
	push {lr}
	bl func_080D53A8
	ldr r0, _080D3504 @ =0x0203C4F0
	bl func_08000F0C
	ldr r3, _080D3508 @ =0x04000208
	movs r0, #0x00
	strh r0, [r3, #0x00]
	ldr r2, _080D350C @ =0x04000200
	ldrh r1, [r2, #0x00]
	ldr r0, _080D3510 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r2, _080D3514 @ =0x04000004
	ldrh r1, [r2, #0x00]
	ldr r0, _080D3518 @ =0x0000FFDF
	ands r0, r1
	strh r0, [r2, #0x00]
	movs r0, #0x01
	strh r0, [r3, #0x00]
	bl func_08006C68
	ldr r0, _080D351C @ =0x02034E81
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D34EE
	ldr r0, _080D3520 @ =0x0203DB10
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r1, #0xFF
	bl func_08120EF8
_080D34EE:
	ldr r0, _080D3524 @ =0x0203C530
	ldr r0, [r0, #0x00]
	bl func_080009C4
	ldr r0, _080D3528 @ =0x0203C504
	ldr r0, [r0, #0x00]
	bl func_080009C4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3504: .4byte 0x0203C4F0
_080D3508: .4byte 0x04000208
_080D350C: .4byte 0x04000200
_080D3510: .4byte 0x0000FFFB
_080D3514: .4byte 0x04000004
_080D3518: .4byte 0x0000FFDF
_080D351C: .4byte 0x02034E81
_080D3520: .4byte 0x0203DB10
_080D3524: .4byte 0x0203C530
_080D3528: .4byte 0x0203C504
	.byte 0x01, 0x49, 0x08, 0x70, 0x70, 0x47, 0x00, 0x00, 0x80, 0x4E, 0x03, 0x02
	thumb_func_start func_080D3538
func_080D3538: @ 080D3538
	push {r4, lr}
	adds r4, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl func_080DED98
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	adds r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _080D355A
	movs r0, #0x00
	b _080D355C
_080D355A:
	movs r0, #0x01
_080D355C:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start func_080D3564
func_080D3564: @ 080D3564
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl func_080DEE44
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	beq _080D3582
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D3586
_080D3582:
	movs r0, #0x00
	b _080D3588
_080D3586:
	movs r0, #0x01
_080D3588:
	pop {r1}
	bx r1
	thumb_func_start func_080D358C
func_080D358C: @ 080D358C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl func_080DEE44
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _080D35AA
	movs r0, #0x00
	b _080D35AC
_080D35AA:
	movs r0, #0x01
_080D35AC:
	pop {r1}
	bx r1
	thumb_func_start func_080D35B0
func_080D35B0: @ 080D35B0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x05C
	mov r8, r0
	ldr r1, _080D3630 @ =0x096FDB70
	mov r0, sp
	movs r2, #0x40
	bl _0811F030
	add r2, sp, #0x040
	adds r1, r2, #0x0
	ldr r0, _080D3634 @ =0x096FDBB0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r6, #0x00
	mov r3, r8
	adds r3, #0x1C
	movs r4, #0x00
	mov r2, r8
	adds r2, #0x0C
	str r3, [sp, #0x058]
	mov r9, r2
_080D35E6:
	lsls r1, r6, #0x02
	adds r0, r3, r1
	str r4, [r0, #0x00]
	adds r1, r2, r1
	str r4, [r1, #0x00]
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x03
	bls _080D35E6
	mov r4, r8
	adds r4, #0x98
	ldrb r0, [r4, #0x00]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r10, r4
	cmp r0, #0x01
	beq _080D361C
	ldrb r0, [r4, #0x00]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bne _080D364C
_080D361C:
	mov r1, r10
	ldrb r0, [r1, #0x00]
	movs r1, #0x08
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D3638
	movs r0, #0x11
	b _080D37A6
_080D3630: .4byte 0x096FDB70
_080D3634: .4byte 0x096FDBB0
_080D3638:
	mov r2, r10
	ldrb r0, [r2, #0x00]
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3660
	movs r0, #0x01
	b _080D37A6
_080D364C:
	mov r3, r10
	ldrb r0, [r3, #0x00]
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3660
	movs r0, #0x00
	b _080D37A6
_080D3660:
	movs r4, #0x00
	str r4, [sp, #0x050]
	movs r6, #0x00
	mov r5, r10
	str r5, [sp, #0x054]
_080D366A:
	ldr r1, [sp, #0x054]
	ldrb r0, [r1, #0x00]
	adds r1, r6, #0x0
	bl func_080D3564
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D367C
	b _080D3790
_080D367C:
	movs r0, #0x01
	lsls r0, r6
	ldr r2, [sp, #0x050]
	adds r2, r2, r0
	str r2, [sp, #0x050]
	mov r3, r10
	ldrb r0, [r3, #0x00]
	adds r1, r6, #0x0
	bl func_080D3538
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D370C
	lsls r4, r6, #0x01
	adds r4, r4, r6
	lsls r4, r4, #0x03
	adds r4, #0x2C
	add r4, r8
	ldr r7, _080D36E4 @ =0x09EF64FC
	adds r0, r4, #0x0
	ldr r1, _080D36E8 @ =0x09EF653C
	adds r2, r7, #0x0
	bl func_08005968
	lsls r5, r6, #0x02
	mov r0, sp
	adds r0, r0, r5
	adds r0, #0x40
	ldrh r1, [r0, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	ldr r4, [sp, #0x058]
	adds r1, r4, r5
	str r0, [r1, #0x00]
	mov r0, r8
	adds r0, #0x9C
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D36F0
	ldr r0, _080D36EC @ =0x0976DEDC
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl func_080026A4
	mov r2, r9
	adds r1, r2, r5
	b _080D378E
_080D36E4: .4byte 0x09EF64FC
_080D36E8: .4byte 0x09EF653C
_080D36EC: .4byte 0x0976DEDC
_080D36F0:
	adds r0, r7, #0x0
	movs r1, #0x10
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D3708 @ =0x0976DEDC
	bl func_080028F8
	mov r3, r9
	adds r1, r3, r5
	b _080D378E
_080D3708: .4byte 0x0976DEDC
_080D370C:
	ldr r4, [sp, #0x054]
	ldrb r0, [r4, #0x00]
	adds r1, r6, #0x0
	bl func_080D358C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3790
	lsls r4, r6, #0x01
	adds r4, r4, r6
	lsls r4, r4, #0x03
	adds r4, #0x2C
	add r4, r8
	ldr r7, _080D376C @ =0x09EF654C
	adds r0, r4, #0x0
	ldr r1, _080D3770 @ =0x09EF658C
	adds r2, r7, #0x0
	bl func_08005968
	lsls r5, r6, #0x02
	mov r0, sp
	adds r0, r0, r5
	adds r0, #0x40
	ldrh r1, [r0, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	ldr r2, [sp, #0x058]
	adds r1, r2, r5
	str r0, [r1, #0x00]
	mov r0, r8
	adds r0, #0x9C
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D3778
	ldr r0, _080D3774 @ =0x0976E4D4
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl func_080026A4
	mov r3, r9
	adds r1, r3, r5
	b _080D378E
	.byte 0x00, 0x00
_080D376C: .4byte 0x09EF654C
_080D3770: .4byte 0x09EF658C
_080D3774: .4byte 0x0976E4D4
_080D3778:
	adds r0, r7, #0x0
	movs r1, #0x10
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D37B8 @ =0x0976E4D4
	bl func_080028F8
	mov r4, r9
	adds r1, r4, r5
_080D378E:
	str r0, [r1, #0x00]
_080D3790:
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x03
	bhi _080D379C
	b _080D366A
_080D379C:
	ldr r5, [sp, #0x050]
	lsls r0, r5, #0x02
	add r0, sp
	ldr r0, [r0, #0x00]
	adds r0, #0x01
_080D37A6:
	add sp, #0x05C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D37B8: .4byte 0x0976E4D4
	thumb_func_start func_080D37BC
func_080D37BC: @ 080D37BC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r5, #0x00
	adds r0, r4, #0x0
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080D37E0
	adds r0, r4, #0x0
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bne _080D37E2
_080D37E0:
	movs r5, #0x01
_080D37E2:
	lsls r0, r5, #0x05
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
