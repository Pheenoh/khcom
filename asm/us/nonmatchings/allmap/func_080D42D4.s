.syntax unified
	.align 2, 0
	.global func_080D42D4
	.thumb
	.thumb_func
	.type func_080D42D4, %function
func_080D42D4: @ 080D42D4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r7, r0, #0x0
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r1, #0x00
	str r1, [sp, #0x000]
	mov r9, r1
	ldr r2, _080D43DC @ =0x096FDC30
	mov r10, r2
_080D42F6:
	mov r0, r10
	ldrh r1, [r0, #0x00]
	ldrh r2, [r7, #0x00]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldrh r0, [r0, #0x02]
	ldrh r2, [r7, #0x02]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	orrs r1, r0
	mov r8, r1
	mov r0, r8
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xFF
	beq _080D43F4
	ldr r0, _080D43E0 @ =0x096FDC40
	add r0, r9
	ldrb r1, [r0, #0x00]
	adds r0, r4, #0x0
	bl func_080D3A70
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D43F4
	adds r0, r4, #0x0
	bl func_080DF548
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x0A
	bne _080D4342
	movs r0, #0x00
_080D4342:
	bl func_080986FC
	movs r1, #0x34
	ldr r2, [sp, #0x000]
	adds r5, r2, #0x0
	muls r5, r1
	adds r1, r7, #0x0
	adds r1, #0x1C
	adds r1, r1, r5
	str r0, [r1, #0x00]
	ldr r0, _080D43E4 @ =0x09618D38
	movs r1, #0x20
	bl func_08002A14
	adds r6, r7, #0x0
	adds r6, #0x28
	adds r6, r6, r5
	str r0, [r6, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x34
	adds r0, r0, r5
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r0, _080D43E8 @ =0x0905E3BA
	movs r1, #0xC0
	lsls r1, r1, #0x03
	bl func_080026A4
	adds r1, r7, #0x0
	adds r1, #0x20
	adds r1, r1, r5
	str r0, [r1, #0x00]
	ldr r0, _080D43E4 @ =0x09618D38
	movs r1, #0x20
	bl func_08002A14
	adds r4, r7, #0x0
	adds r4, #0x2C
	adds r4, r4, r5
	str r0, [r4, #0x00]
	adds r1, r7, #0x0
	adds r1, #0x38
	adds r1, r1, r5
	ldr r0, _080D43EC @ =0x09EE97F4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [r6, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, [r4, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	adds r1, r7, #0x0
	adds r1, #0x08
	add r1, r9
	ldr r0, _080D43F0 @ =0x09EF64E8
	add r0, r9
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	b _080D43FE
	.byte 0x00, 0x00
_080D43DC: .4byte 0x096FDC30
_080D43E0: .4byte 0x096FDC40
_080D43E4: .4byte 0x09618D38
_080D43E8: .4byte 0x0905E3BA
_080D43EC: .4byte 0x09EE97F4
_080D43F0: .4byte 0x09EF64E8
_080D43F4:
	adds r0, r7, #0x0
	adds r0, #0x08
	add r0, r9
	movs r1, #0x00
	str r1, [r0, #0x00]
_080D43FE:
	movs r1, #0x04
	add r9, r1
	add r10, r1
	ldr r2, [sp, #0x000]
	adds r2, #0x01
	str r2, [sp, #0x000]
	cmp r2, #0x03
	bgt _080D4410
	b _080D42F6
_080D4410:
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D447A
	ldr r0, _080D448C @ =0x0976DD62
	movs r1, #0x80
	bl func_080026A4
	str r0, [r7, #0x18]
	ldr r0, _080D4490 @ =0x0984A1D8
	movs r1, #0x20
	bl func_08002A14
	adds r1, r7, #0x0
	adds r1, #0xEC
	str r0, [r1, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, _080D4494 @ =0x0976B340
	movs r1, #0x90
	lsls r1, r1, #0x06
	bl func_080026A4
	adds r1, r7, #0x0
	adds r1, #0xF0
	str r0, [r1, #0x00]
	adds r1, #0x08
	ldr r0, _080D4498 @ =0x09EF6424
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r4, r7, #0x0
	adds r4, #0xF4
	ldr r0, [r4, #0x00]
	ldr r2, _080D449C @ =0x0984A0F8
	movs r1, #0x0F
	movs r3, #0x20
	bl func_0800388C
	ldr r0, [r4, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
_080D447A:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D448C: .4byte 0x0976DD62
_080D4490: .4byte 0x0984A1D8
_080D4494: .4byte 0x0976B340
_080D4498: .4byte 0x09EF6424
_080D449C: .4byte 0x0984A0F8
.syntax divided
