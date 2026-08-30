.syntax unified
	.align 2, 0
	.global func_080AD144
	.thumb
	.thumb_func
	.type func_080AD144, %function
func_080AD144: @ 080AD144
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	mov r8, r3
	ldr r6, [sp, #0x030]
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	add r0, sp, #0x004
	movs r1, #0x00
	movs r2, #0x0C
	bl memset
	movs r0, #0x00
	mov r9, r0
	movs r2, #0x00
	cmp r9, r4
	bcs _080AD18C
_080AD170:
	lsls r0, r2, #0x02
	mov r1, sp
	adds r1, r1, r0
	adds r1, #0x04
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x48]
	ldrh r0, [r0, #0x28]
	str r0, [r1, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r4
	bcc _080AD170
_080AD18C:
	ldr r0, _080AD1E0 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080AD1EC
	ldr r0, _080AD1E4 @ =0x02039B84
	ldr r3, [r0, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080AD1EC
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r1, r0
	cmp r1, #0x00
	bne _080AD1EC
	ldr r0, _080AD1E8 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xEE
	ldrb r0, [r2, #0x00]
	cmp r0, #0x01
	beq _080AD1D6
	movs r0, #0xE4
	lsls r0, r0, #0x01
	adds r0, r0, r3
	mov r12, r0
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x1D
	ble _080AD1EC
_080AD1D6:
	strb r1, [r2, #0x00]
	movs r0, #0x6C
	bl _080ADCF4
	lsls r0, r0, #0x00
_080AD1E0:
	ldr r3, [sp, #0x2C0]
	lsls r3, r0, #0x08
_080AD1E4:
	ldr r3, [sp, #0x210]
	lsls r3, r0, #0x08
_080AD1E8:
	ldr r5, [sp, #0x350]
	lsls r3, r0, #0x08
_080AD1EC:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x0A
	ldr r1, [sp, #0x004]
	orrs r1, r0
	ldr r0, [sp, #0x00C]
	lsls r0, r0, #0x14
	orrs r1, r0
	lsls r0, r4, #0x1E
	orrs r1, r0
	ldr r0, _080AD248 @ =0xCC9324C9
	cmp r1, r0
	bne _080AD206
	b _080AD79C
_080AD206:
	cmp r1, r0
	bls _080AD20C
	b _080AD468
_080AD20C:
	ldr r0, _080AD24C @ =0x800A7E9F
	cmp r1, r0
	bne _080AD214
	b _080AD744
_080AD214:
	cmp r1, r0
	bls _080AD21A
	b _080AD358
_080AD21A:
	ldr r0, _080AD250 @ =0x80043D0F
	cmp r1, r0
	bne _080AD222
	b _080AD718
_080AD222:
	cmp r1, r0
	bhi _080AD2C4
	ldr r0, _080AD254 @ =0x80034CD3
	cmp r1, r0
	bne _080AD22E
	b _080AD700
_080AD22E:
	cmp r1, r0
	bhi _080AD27C
	ldr r0, _080AD258 @ =0x8002D4B5
	cmp r1, r0
	bne _080AD23A
	b _080AD6F8
_080AD23A:
	cmp r1, r0
	bhi _080AD260
	ldr r0, _080AD25C @ =0x8002ACAB
	cmp r1, r0
	bne _080AD246
	b _080AD6F0
_080AD246:
	b _080AD8D8
_080AD248: .4byte 0xCC9324C9
_080AD24C: .4byte 0x800A7E9F
_080AD250: .4byte 0x80043D0F
_080AD254: .4byte 0x80034CD3
_080AD258: .4byte 0x8002D4B5
_080AD25C: .4byte 0x8002ACAB
_080AD260:
	ldr r0, _080AD274 @ =0x8002FCBF
	cmp r1, r0
	bne _080AD268
	b _080AD6F4
_080AD268:
	ldr r0, _080AD278 @ =0x800324C9
	cmp r1, r0
	bne _080AD270
	b _080AD6FC
_080AD270:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD274: .4byte 0x8002FCBF
_080AD278: .4byte 0x800324C9
_080AD27C:
	ldr r0, _080AD29C @ =0x8003C4F1
	cmp r1, r0
	bne _080AD284
	b _080AD710
_080AD284:
	cmp r1, r0
	bhi _080AD2A8
	ldr r0, _080AD2A0 @ =0x800374DD
	cmp r1, r0
	bne _080AD290
	b _080AD704
_080AD290:
	ldr r0, _080AD2A4 @ =0x80039CE7
	cmp r1, r0
	bne _080AD298
	b _080AD708
_080AD298:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD29C: .4byte 0x8003C4F1
_080AD2A0: .4byte 0x800374DD
_080AD2A4: .4byte 0x80039CE7
_080AD2A8:
	ldr r0, _080AD2BC @ =0x8003ECFB
	cmp r1, r0
	bne _080AD2B0
	b _080AD70C
_080AD2B0:
	ldr r0, _080AD2C0 @ =0x80041505
	cmp r1, r0
	bne _080AD2B8
	b _080AD714
_080AD2B8:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD2BC: .4byte 0x8003ECFB
_080AD2C0: .4byte 0x80041505
_080AD2C4:
	ldr r0, _080AD2E8 @ =0x80050541
	cmp r1, r0
	bne _080AD2CC
	b _080AD72C
_080AD2CC:
	cmp r1, r0
	bhi _080AD310
	ldr r0, _080AD2EC @ =0x80048D23
	cmp r1, r0
	bne _080AD2D8
	b _080AD720
_080AD2D8:
	cmp r1, r0
	bhi _080AD2F4
	ldr r0, _080AD2F0 @ =0x80046519
	cmp r1, r0
	bne _080AD2E4
	b _080AD71C
_080AD2E4:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD2E8: .4byte 0x80050541
_080AD2EC: .4byte 0x80048D23
_080AD2F0: .4byte 0x80046519
_080AD2F4:
	ldr r0, _080AD308 @ =0x8004B52D
	cmp r1, r0
	bne _080AD2FC
	b _080AD724
_080AD2FC:
	ldr r0, _080AD30C @ =0x8004DD37
	cmp r1, r0
	bne _080AD304
	b _080AD728
_080AD304:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD308: .4byte 0x8004B52D
_080AD30C: .4byte 0x8004DD37
_080AD310:
	ldr r0, _080AD330 @ =0x80057D5F
	cmp r1, r0
	bne _080AD318
	b _080AD738
_080AD318:
	cmp r1, r0
	bhi _080AD33C
	ldr r0, _080AD334 @ =0x80052D4B
	cmp r1, r0
	bne _080AD324
	b _080AD730
_080AD324:
	ldr r0, _080AD338 @ =0x80055555
	cmp r1, r0
	bne _080AD32C
	b _080AD734
_080AD32C:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD330: .4byte 0x80057D5F
_080AD334: .4byte 0x80052D4B
_080AD338: .4byte 0x80055555
_080AD33C:
	ldr r0, _080AD350 @ =0x8005A569
	cmp r1, r0
	bne _080AD344
	b _080AD73C
_080AD344:
	ldr r0, _080AD354 @ =0x8005CD73
	cmp r1, r0
	bne _080AD34C
	b _080AD740
_080AD34C:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD350: .4byte 0x8005A569
_080AD354: .4byte 0x8005CD73
_080AD358:
	ldr r0, _080AD380 @ =0xC6519465
	cmp r1, r0
	bne _080AD360
	b _080AD748
_080AD360:
	cmp r1, r0
	bhi _080AD3DC
	ldr r0, _080AD384 @ =0xC290A429
	cmp r1, r0
	bne _080AD36C
	b _080AD748
_080AD36C:
	cmp r1, r0
	bhi _080AD3A4
	ldr r0, _080AD388 @ =0xC0B02C0B
	cmp r1, r0
	bne _080AD378
	b _080AD748
_080AD378:
	cmp r1, r0
	bhi _080AD390
	ldr r0, _080AD38C @ =0xC0100401
	b _080AD40E
_080AD380: .4byte 0xC6519465
_080AD384: .4byte 0xC290A429
_080AD388: .4byte 0xC0B02C0B
_080AD38C: .4byte 0xC0100401
_080AD390:
	ldr r0, _080AD39C @ =0xC1505415
	cmp r1, r0
	bne _080AD398
	b _080AD748
_080AD398:
	ldr r0, _080AD3A0 @ =0xC1F07C1F
	b _080AD40E
_080AD39C: .4byte 0xC1505415
_080AD3A0: .4byte 0xC1F07C1F
_080AD3A4:
	ldr r0, _080AD3BC @ =0xC4711C47
	cmp r1, r0
	bne _080AD3AC
	b _080AD748
_080AD3AC:
	cmp r1, r0
	bhi _080AD3C8
	ldr r0, _080AD3C0 @ =0xC330CC33
	cmp r1, r0
	bne _080AD3B8
	b _080AD748
_080AD3B8:
	ldr r0, _080AD3C4 @ =0xC3D0F43D
	b _080AD40E
_080AD3BC: .4byte 0xC4711C47
_080AD3C0: .4byte 0xC330CC33
_080AD3C4: .4byte 0xC3D0F43D
_080AD3C8:
	ldr r0, _080AD3D4 @ =0xC5114451
	cmp r1, r0
	bne _080AD3D0
	b _080AD748
_080AD3D0:
	ldr r0, _080AD3D8 @ =0xC5B16C5B
	b _080AD40E
_080AD3D4: .4byte 0xC5114451
_080AD3D8: .4byte 0xC5B16C5B
_080AD3DC:
	ldr r0, _080AD3F8 @ =0xC9725C97
	cmp r1, r0
	bne _080AD3E4
	b _080AD748
_080AD3E4:
	cmp r1, r0
	bhi _080AD420
	ldr r0, _080AD3FC @ =0xC791E479
	cmp r1, r0
	bne _080AD3F0
	b _080AD748
_080AD3F0:
	cmp r1, r0
	bhi _080AD404
	ldr r0, _080AD400 @ =0xC6F1BC6F
	b _080AD40E
_080AD3F8: .4byte 0xC9725C97
_080AD3FC: .4byte 0xC791E479
_080AD400: .4byte 0xC6F1BC6F
_080AD404:
	ldr r0, _080AD418 @ =0xC8320C83
	cmp r1, r0
	bne _080AD40C
	b _080AD748
_080AD40C:
	ldr r0, _080AD41C @ =0xC8D2348D
_080AD40E:
	cmp r1, r0
	bne _080AD414
	b _080AD748
_080AD414:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD418: .4byte 0xC8320C83
_080AD41C: .4byte 0xC8D2348D
_080AD420:
	ldr r0, _080AD440 @ =0xCAB2AD37
	cmp r1, r0
	bne _080AD428
	b _080AD81E
_080AD428:
	cmp r1, r0
	bhi _080AD44C
	ldr r0, _080AD444 @ =0xCA1284A1
	cmp r1, r0
	bne _080AD434
	b _080AD748
_080AD434:
	ldr r0, _080AD448 @ =0xCAB2ACAB
	cmp r1, r0
	bne _080AD43C
	b _080AD790
_080AD43C:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD440: .4byte 0xCAB2AD37
_080AD444: .4byte 0xCA1284A1
_080AD448: .4byte 0xCAB2ACAB
_080AD44C:
	ldr r0, _080AD460 @ =0xCB52D4B5
	cmp r1, r0
	bne _080AD454
	b _080AD794
_080AD454:
	ldr r0, _080AD464 @ =0xCBF2FCBF
	cmp r1, r0
	bne _080AD45C
	b _080AD798
_080AD45C:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD460: .4byte 0xCB52D4B5
_080AD464: .4byte 0xCBF2FCBF
_080AD468:
	ldr r0, _080AD4A4 @ =0xE95A5695
	cmp r1, r0
	bne _080AD470
	b _080AD842
_080AD470:
	cmp r1, r0
	bls _080AD476
	b _080AD5AC
_080AD476:
	ldr r0, _080AD4A8 @ =0xD0F43D0F
	cmp r1, r0
	bne _080AD47E
	b _080AD7B8
_080AD47E:
	cmp r1, r0
	bhi _080AD518
	ldr r0, _080AD4AC @ =0xCE734CDD
	cmp r1, r0
	bne _080AD48A
	b _080AD7FA
_080AD48A:
	cmp r1, r0
	bhi _080AD4D4
	ldr r0, _080AD4B0 @ =0xCDD374DD
	cmp r1, r0
	bne _080AD496
	b _080AD7A4
_080AD496:
	cmp r1, r0
	bhi _080AD4B8
	ldr r0, _080AD4B4 @ =0xCD334CD3
	cmp r1, r0
	bne _080AD4A2
	b _080AD7A0
_080AD4A2:
	b _080AD8D8
_080AD4A4: .4byte 0xE95A5695
_080AD4A8: .4byte 0xD0F43D0F
_080AD4AC: .4byte 0xCE734CDD
_080AD4B0: .4byte 0xCDD374DD
_080AD4B4: .4byte 0xCD334CD3
_080AD4B8:
	ldr r0, _080AD4CC @ =0xCE72ACB5
	cmp r1, r0
	bne _080AD4C0
	b _080AD80C
_080AD4C0:
	ldr r0, _080AD4D0 @ =0xCE734CC9
	cmp r1, r0
	bne _080AD4C8
	b _080AD830
_080AD4C8:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD4CC: .4byte 0xCE72ACB5
_080AD4D0: .4byte 0xCE734CC9
_080AD4D4:
	ldr r0, _080AD4F4 @ =0xCF13C4F1
	cmp r1, r0
	bne _080AD4DC
	b _080AD7B0
_080AD4DC:
	cmp r1, r0
	bhi _080AD4FC
	ldr r0, _080AD4F8 @ =0xCE739CDD
	cmp r1, r0
	bne _080AD4E8
	b _080AD7E8
_080AD4E8:
	adds r0, #0x0A
	cmp r1, r0
	bne _080AD4F0
	b _080AD7A8
_080AD4F0:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD4F4: .4byte 0xCF13C4F1
_080AD4F8: .4byte 0xCE739CDD
_080AD4FC:
	ldr r0, _080AD510 @ =0xCFB3ECFB
	cmp r1, r0
	bne _080AD504
	b _080AD7AC
_080AD504:
	ldr r0, _080AD514 @ =0xD0541505
	cmp r1, r0
	bne _080AD50C
	b _080AD7B4
_080AD50C:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD510: .4byte 0xCFB3ECFB
_080AD514: .4byte 0xD0541505
_080AD518:
	ldr r0, _080AD53C @ =0xD4150541
	cmp r1, r0
	bne _080AD520
	b _080AD7CC
_080AD520:
	cmp r1, r0
	bhi _080AD564
	ldr r0, _080AD540 @ =0xD2348D23
	cmp r1, r0
	bne _080AD52C
	b _080AD7C0
_080AD52C:
	cmp r1, r0
	bhi _080AD548
	ldr r0, _080AD544 @ =0xD1946519
	cmp r1, r0
	bne _080AD538
	b _080AD7BC
_080AD538:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD53C: .4byte 0xD4150541
_080AD540: .4byte 0xD2348D23
_080AD544: .4byte 0xD1946519
_080AD548:
	ldr r0, _080AD55C @ =0xD2D4B52D
	cmp r1, r0
	bne _080AD550
	b _080AD7C4
_080AD550:
	ldr r0, _080AD560 @ =0xD374DD37
	cmp r1, r0
	bne _080AD558
	b _080AD7C8
_080AD558:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD55C: .4byte 0xD2D4B52D
_080AD560: .4byte 0xD374DD37
_080AD564:
	ldr r0, _080AD584 @ =0xD5F57D5F
	cmp r1, r0
	bne _080AD56C
	b _080AD7D8
_080AD56C:
	cmp r1, r0
	bhi _080AD590
	ldr r0, _080AD588 @ =0xD4B52D4B
	cmp r1, r0
	bne _080AD578
	b _080AD7D0
_080AD578:
	ldr r0, _080AD58C @ =0xD5555555
	cmp r1, r0
	bne _080AD580
	b _080AD7D4
_080AD580:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD584: .4byte 0xD5F57D5F
_080AD588: .4byte 0xD4B52D4B
_080AD58C: .4byte 0xD5555555
_080AD590:
	ldr r0, _080AD5A4 @ =0xD695A569
	cmp r1, r0
	bne _080AD598
	b _080AD7DC
_080AD598:
	ldr r0, _080AD5A8 @ =0xD735CD73
	cmp r1, r0
	bne _080AD5A0
	b _080AD7E0
_080AD5A0:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD5A4: .4byte 0xD695A569
_080AD5A8: .4byte 0xD735CD73
_080AD5AC:
	ldr r0, _080AD5DC @ =0xF21CAF21
	cmp r1, r0
	bne _080AD5B4
	b _080AD8BC
_080AD5B4:
	cmp r1, r0
	bhi _080AD650
	ldr r0, _080AD5E0 @ =0xED1B1EC7
	cmp r1, r0
	bne _080AD5C0
	b _080AD8A0
_080AD5C0:
	cmp r1, r0
	bhi _080AD608
	ldr r0, _080AD5E4 @ =0xEB3AA6B3
	cmp r1, r0
	bne _080AD5CC
	b _080AD88C
_080AD5CC:
	cmp r1, r0
	bhi _080AD5EC
	ldr r0, _080AD5E8 @ =0xE9FA7E9F
	cmp r1, r0
	bne _080AD5D8
	b _080AD7E4
_080AD5D8:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD5DC: .4byte 0xF21CAF21
_080AD5E0: .4byte 0xED1B1EC7
_080AD5E4: .4byte 0xEB3AA6B3
_080AD5E8: .4byte 0xE9FA7E9F
_080AD5EC:
	ldr r0, _080AD600 @ =0xEB3ACEB3
	cmp r1, r0
	bne _080AD5F4
	b _080AD888
_080AD5F4:
	ldr r0, _080AD604 @ =0xED1AF6BD
	cmp r1, r0
	bne _080AD5FC
	b _080AD89C
_080AD5FC:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD600: .4byte 0xEB3ACEB3
_080AD604: .4byte 0xED1AF6BD
_080AD608:
	ldr r0, _080AD628 @ =0xF0DBE6F9
	cmp r1, r0
	bne _080AD610
	b _080AD8A4
_080AD610:
	cmp r1, r0
	bhi _080AD634
	ldr r0, _080AD62C @ =0xEE5B96E5
	cmp r1, r0
	bne _080AD61C
	b _080AD890
_080AD61C:
	ldr r0, _080AD630 @ =0xEEFB96EF
	cmp r1, r0
	bne _080AD624
	b _080AD894
_080AD624:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD628: .4byte 0xF0DBE6F9
_080AD62C: .4byte 0xEE5B96E5
_080AD630: .4byte 0xEEFB96EF
_080AD634:
	ldr r0, _080AD648 @ =0xF17C0F03
	cmp r1, r0
	bne _080AD63C
	b _080AD8B4
_080AD63C:
	ldr r0, _080AD64C @ =0xF21C8721
	cmp r1, r0
	bne _080AD644
	b _080AD884
_080AD644:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD648: .4byte 0xF17C0F03
_080AD64C: .4byte 0xF21C8721
_080AD650:
	ldr r0, _080AD67C @ =0xF5DD4F53
	cmp r1, r0
	bne _080AD658
	b _080AD8B0
_080AD658:
	cmp r1, r0
	bhi _080AD6A8
	ldr r0, _080AD680 @ =0xF53D4F53
	cmp r1, r0
	bne _080AD664
	b _080AD8D4
_080AD664:
	cmp r1, r0
	bhi _080AD68C
	ldr r0, _080AD684 @ =0xF35CFF3F
	cmp r1, r0
	bne _080AD670
	b _080AD8B8
_080AD670:
	ldr r0, _080AD688 @ =0xF49D2735
	cmp r1, r0
	bne _080AD678
	b _080AD898
_080AD678:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD67C: .4byte 0xF5DD4F53
_080AD680: .4byte 0xF53D4F53
_080AD684: .4byte 0xF35CFF3F
_080AD688: .4byte 0xF49D2735
_080AD68C:
	ldr r0, _080AD6A0 @ =0xF53D4F5D
	cmp r1, r0
	bne _080AD694
	b _080AD8AC
_080AD694:
	ldr r0, _080AD6A4 @ =0xF53D7753
	cmp r1, r0
	bne _080AD69C
	b _080AD8A8
_080AD69C:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD6A0: .4byte 0xF53D4F5D
_080AD6A4: .4byte 0xF53D7753
_080AD6A8:
	ldr r0, _080AD6C8 @ =0xF85E3F85
	cmp r1, r0
	bne _080AD6B0
	b _080AD8D0
_080AD6B0:
	cmp r1, r0
	bhi _080AD6D4
	ldr r0, _080AD6CC @ =0xF71D9F71
	cmp r1, r0
	bne _080AD6BC
	b _080AD8C0
_080AD6BC:
	ldr r0, _080AD6D0 @ =0xF7BDC767
	cmp r1, r0
	bne _080AD6C4
	b _080AD8C4
_080AD6C4:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD6C8: .4byte 0xF85E3F85
_080AD6CC: .4byte 0xF71D9F71
_080AD6D0: .4byte 0xF7BDC767
_080AD6D4:
	ldr r0, _080AD6E8 @ =0xFA3EB7A3
	cmp r1, r0
	bne _080AD6DC
	b _080AD8CC
_080AD6DC:
	ldr r0, _080AD6EC @ =0xFADEB7A3
	cmp r1, r0
	bne _080AD6E4
	b _080AD8C8
_080AD6E4:
	b _080AD8D8
	.byte 0x00, 0x00
_080AD6E8: .4byte 0xFA3EB7A3
_080AD6EC: .4byte 0xFADEB7A3
_080AD6F0:
	movs r0, #0x00
	b _080ADCF4
_080AD6F4:
	movs r0, #0x02
	b _080ADCF4
_080AD6F8:
	movs r0, #0x01
	b _080ADCF4
_080AD6FC:
	movs r0, #0x03
	b _080ADCF4
_080AD700:
	movs r0, #0x0B
	b _080ADCF4
_080AD704:
	movs r0, #0x04
	b _080ADCF4
_080AD708:
	movs r0, #0x2C
	b _080ADCF4
_080AD70C:
	movs r0, #0x0F
	b _080ADCF4
_080AD710:
	movs r0, #0x11
	b _080ADCF4
_080AD714:
	movs r0, #0x13
	b _080ADCF4
_080AD718:
	movs r0, #0x15
	b _080ADCF4
_080AD71C:
	movs r0, #0x17
	b _080ADCF4
_080AD720:
	movs r0, #0x19
	b _080ADCF4
_080AD724:
	movs r0, #0x1B
	b _080ADCF4
_080AD728:
	movs r0, #0x1D
	b _080ADCF4
_080AD72C:
	movs r0, #0x1F
	b _080ADCF4
_080AD730:
	movs r0, #0x21
	b _080ADCF4
_080AD734:
	movs r0, #0x23
	b _080ADCF4
_080AD738:
	movs r0, #0x25
	b _080ADCF4
_080AD73C:
	movs r0, #0x27
	b _080ADCF4
_080AD740:
	movs r0, #0x29
	b _080ADCF4
_080AD744:
	movs r0, #0x2B
	b _080ADCF4
_080AD748:
	adds r0, r7, #0x0
	subs r0, #0x0A
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bhi _080AD76A
	movs r0, #0x00
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD76A
	movs r0, #0x32
	mov r1, r8
	str r0, [r1, #0x00]
	b _080ADCF4
_080AD76A:
	adds r0, r7, #0x0
	subs r0, #0x14
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x03
	bls _080AD778
	b _080AD8D8
_080AD778:
	movs r0, #0x02
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080AD788
	b _080AD8D8
_080AD788:
	movs r0, #0x33
	mov r3, r8
	str r0, [r3, #0x00]
	b _080ADCF4
_080AD790:
	movs r0, #0x07
	b _080ADCF4
_080AD794:
	movs r0, #0x08
	b _080ADCF4
_080AD798:
	movs r0, #0x09
	b _080ADCF4
_080AD79C:
	movs r0, #0x0A
	b _080ADCF4
_080AD7A0:
	movs r0, #0x0C
	b _080ADCF4
_080AD7A4:
	movs r0, #0x0D
	b _080ADCF4
_080AD7A8:
	movs r0, #0x2D
	b _080ADCF4
_080AD7AC:
	movs r0, #0x0E
	b _080ADCF4
_080AD7B0:
	movs r0, #0x10
	b _080ADCF4
_080AD7B4:
	movs r0, #0x12
	b _080ADCF4
_080AD7B8:
	movs r0, #0x14
	b _080ADCF4
_080AD7BC:
	movs r0, #0x16
	b _080ADCF4
_080AD7C0:
	movs r0, #0x18
	b _080ADCF4
_080AD7C4:
	movs r0, #0x1A
	b _080ADCF4
_080AD7C8:
	movs r0, #0x1C
	b _080ADCF4
_080AD7CC:
	movs r0, #0x1E
	b _080ADCF4
_080AD7D0:
	movs r0, #0x20
	b _080ADCF4
_080AD7D4:
	movs r0, #0x22
	b _080ADCF4
_080AD7D8:
	movs r0, #0x24
	b _080ADCF4
_080AD7DC:
	movs r0, #0x26
	b _080ADCF4
_080AD7E0:
	movs r0, #0x28
	b _080ADCF4
_080AD7E4:
	movs r0, #0x2A
	b _080ADCF4
_080AD7E8:
	movs r0, #0x27
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD8D8
	movs r0, #0x35
	b _080ADCF4
_080AD7FA:
	movs r0, #0x26
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD8D8
	movs r0, #0x36
	b _080ADCF4
_080AD80C:
	movs r0, #0x22
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD8D8
	movs r0, #0x41
	b _080ADCF4
_080AD81E:
	movs r0, #0x20
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD8D8
	movs r0, #0x46
	b _080ADCF4
_080AD830:
	movs r0, #0x2B
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD8D8
	movs r0, #0x4D
	b _080ADCF4
_080AD842:
	ldr r0, _080AD868 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	beq _080AD8D8
	subs r0, r7, #0x5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x0A
	bhi _080AD86C
	movs r0, #0x52
	b _080ADCF4
	.byte 0x00, 0x00
_080AD868: .4byte 0x02039B84
_080AD86C:
	adds r0, r7, #0x0
	subs r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x09
	bhi _080AD87C
	movs r0, #0x53
	b _080ADCF4
_080AD87C:
	cmp r7, #0x1A
	bls _080AD8D8
	movs r0, #0x54
	b _080ADCF4
_080AD884:
	movs r0, #0x55
	b _080ADCF4
_080AD888:
	movs r0, #0x56
	b _080ADCF4
_080AD88C:
	movs r0, #0x57
	b _080ADCF4
_080AD890:
	movs r0, #0x58
	b _080ADCF4
_080AD894:
	movs r0, #0x59
	b _080ADCF4
_080AD898:
	movs r0, #0x5A
	b _080ADCF4
_080AD89C:
	movs r0, #0x5B
	b _080ADCF4
_080AD8A0:
	movs r0, #0x5C
	b _080ADCF4
_080AD8A4:
	movs r0, #0x5D
	b _080ADCF4
_080AD8A8:
	movs r0, #0x5E
	b _080ADCF4
_080AD8AC:
	movs r0, #0x5F
	b _080ADCF4
_080AD8B0:
	movs r0, #0x60
	b _080ADCF4
_080AD8B4:
	movs r0, #0x61
	b _080ADCF4
_080AD8B8:
	movs r0, #0x62
	b _080ADCF4
_080AD8BC:
	movs r0, #0x63
	b _080ADCF4
_080AD8C0:
	movs r0, #0x64
	b _080ADCF4
_080AD8C4:
	movs r0, #0x65
	b _080ADCF4
_080AD8C8:
	movs r0, #0x66
	b _080ADCF4
_080AD8CC:
	movs r0, #0x67
	b _080ADCF4
_080AD8D0:
	movs r0, #0x68
	b _080ADCF4
_080AD8D4:
	movs r0, #0x69
	b _080ADCF4
_080AD8D8:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x2B
	bl func_080ADF94
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080AD8F6
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080ADFD4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD908
_080AD8F6:
	movs r0, #0x2A
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD908
	movs r0, #0x37
	b _080ADCF4
_080AD908:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE080
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD928
	movs r0, #0x29
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD928
	movs r0, #0x38
	b _080ADCF4
_080AD928:
	adds r0, r5, #0x0
	movs r1, #0x17
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD94A
	movs r0, #0x1B
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD94A
	movs r0, #0x3A
	b _080ADCF4
_080AD94A:
	adds r0, r5, #0x0
	movs r1, #0x18
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD96C
	movs r0, #0x1C
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD96C
	movs r0, #0x3B
	b _080ADCF4
_080AD96C:
	adds r0, r5, #0x0
	movs r1, #0x1F
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD98E
	movs r0, #0x1D
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD98E
	movs r0, #0x3C
	b _080ADCF4
_080AD98E:
	adds r0, r5, #0x0
	movs r1, #0x12
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD9B0
	movs r0, #0x17
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD9B0
	movs r0, #0x3D
	b _080ADCF4
_080AD9B0:
	adds r0, r5, #0x0
	movs r1, #0x13
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD9D2
	movs r0, #0x18
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD9D2
	movs r0, #0x3E
	b _080ADCF4
_080AD9D2:
	adds r0, r5, #0x0
	movs r1, #0x14
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD9F4
	movs r0, #0x19
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080AD9F4
	movs r0, #0x3F
	b _080ADCF4
_080AD9F4:
	adds r0, r5, #0x0
	movs r1, #0x16
	adds r2, r4, #0x0
	bl func_080ADEAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADA16
	movs r0, #0x1A
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADA16
	movs r0, #0x40
	b _080ADCF4
_080ADA16:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE0B4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADA36
	movs r0, #0x2E
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADA36
	movs r0, #0x42
	b _080ADCF4
_080ADA36:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE0F4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADA56
	movs r0, #0x3A
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADA56
	movs r0, #0x43
	b _080ADCF4
_080ADA56:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE014
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADA76
	movs r0, #0x2C
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADA76
	movs r0, #0x45
	b _080ADCF4
_080ADA76:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080ADF60
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADA96
	movs r0, #0x1F
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADA96
	movs r0, #0x47
	b _080ADCF4
_080ADA96:
	adds r0, r5, #0x0
	movs r1, #0x19
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_080ADEEC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADABA
	movs r0, #0x23
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADABA
	movs r0, #0x48
	b _080ADCF4
_080ADABA:
	adds r0, r5, #0x0
	movs r1, #0x1B
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_080ADEEC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADADE
	movs r0, #0x32
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADADE
	movs r0, #0x49
	b _080ADCF4
_080ADADE:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE134
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADAFE
	movs r0, #0x38
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADAFE
	movs r0, #0x4A
	b _080ADCF4
_080ADAFE:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE168
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADB1E
	movs r0, #0x1E
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADB1E
	movs r0, #0x4B
	b _080ADCF4
_080ADB1E:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE1A8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADB3E
	movs r0, #0x21
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADB3E
	movs r0, #0x4C
	b _080ADCF4
_080ADB3E:
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x16
	movs r3, #0x17
	bl func_080ADE2C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADB66
	movs r0, #0x28
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADB66
	movs r0, #0x4E
	b _080ADCF4
_080ADB66:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x18
	movs r3, #0x16
	bl func_080ADE78
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADB8A
	movs r0, #0x24
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADB8A
	movs r0, #0x4F
	b _080ADCF4
_080ADB8A:
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x16
	movs r3, #0x19
	bl func_080ADE2C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADBB2
	movs r0, #0x25
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADBB2
	movs r0, #0x50
	b _080ADCF4
_080ADBB2:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080AE1E8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADBD2
	movs r0, #0x2D
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADBD2
	movs r0, #0x51
	b _080ADCF4
_080ADBD2:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080ADD04
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADC24
	adds r0, r7, #0x0
	subs r0, #0x0A
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bhi _080ADC02
	movs r0, #0x01
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADC02
	movs r0, #0x2E
	mov r1, r8
	str r0, [r1, #0x00]
	b _080ADCF4
_080ADC02:
	adds r0, r7, #0x0
	subs r0, #0x14
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x03
	bhi _080ADC24
	movs r0, #0x05
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADC24
	movs r0, #0x05
	mov r3, r8
	str r0, [r3, #0x00]
	b _080ADCF4
_080ADC24:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080ADD58
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADCB2
	subs r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bhi _080ADC52
	movs r0, #0x06
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADC52
	movs r0, #0x2F
	mov r1, r8
	str r0, [r1, #0x00]
	b _080ADCF4
_080ADC52:
	adds r0, r7, #0x0
	subs r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	bhi _080ADC74
	movs r0, #0x04
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADC74
	movs r0, #0x06
	mov r3, r8
	str r0, [r3, #0x00]
	b _080ADCF4
_080ADC74:
	subs r0, r7, #0x7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	bhi _080ADC94
	movs r0, #0x07
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADC94
	movs r0, #0x30
	mov r1, r8
	str r0, [r1, #0x00]
	b _080ADCF4
_080ADC94:
	cmp r7, #0x00
	beq _080ADC9C
	cmp r7, #0x1B
	bne _080ADCB2
_080ADC9C:
	movs r0, #0x03
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADCB2
	movs r0, #0x34
	mov r3, r8
	str r0, [r3, #0x00]
	b _080ADCF4
_080ADCB2:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080ADDA8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADCD6
	movs r0, #0x08
	adds r1, r6, #0x0
	bl func_080AE274
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080ADCD6
	movs r0, #0x31
	mov r1, r8
	str r0, [r1, #0x00]
	b _080ADCF4
_080ADCD6:
	ldr r0, [sp, #0x02C]
	mov r3, r9
	strb r3, [r0, #0x00]
	mov r0, r9
	cmp r0, #0x00
	bne _080ADCE6
	movs r0, #0x6A
	b _080ADCF4
_080ADCE6:
	mov r1, r9
	cmp r1, #0x01
	beq _080ADCF0
	movs r0, #0x6B
	b _080ADCF4
_080ADCF0:
	mov r3, r8
	ldr r0, [r3, #0x00]
_080ADCF4:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
